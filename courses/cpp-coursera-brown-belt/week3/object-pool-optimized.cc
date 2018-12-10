template <class T>
class ObjectPool {
public:
  T* Allocate();
  T* TryAllocate();

  void Deallocate(T* object);

private:
  queue<unique_ptr<T>> free;
  set<unique_ptr<T>, less<>> allocated;  // Изменили на set
};

template <typename T>
T* ObjectPool<T>::Allocate() {
  if (free.empty()) {
    free.push(make_unique<T>());
  }
  auto ptr = move(free.front());
  free.pop();
  T* ret = ptr.get();
  allocated.insert(move(ptr));  // Изменили вставку
  return ret;
}

template <typename T>
T* ObjectPool<T>::TryAllocate() {
  if (free.empty()) {
    return nullptr;
  }
  return Allocate();
}

// Дописали функции сравнения
template<class T>
bool operator<(const unique_ptr<T>& lhs, const T* rhs) {
  return lhs.get() < rhs;
}
template<class T>
bool operator<(const T* lhs, const unique_ptr<T>& rhs) {
  return lhs < rhs.get();
}

template <typename T>
void ObjectPool<T>::Deallocate(T* object) {
  auto it = allocated.find(object);
  if (it == allocated.end()) {
    throw invalid_argument("");
  }
  // Изменили код перемещения
  free.push(move(allocated.extract(it).value()));
}
