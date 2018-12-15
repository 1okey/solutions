#include "Common.h"
#include "Textures.h"
#include "test_runner.h"

#include <iostream>
#include <map>

using namespace std;

class Shape: public IShape {
public:
  void SetPosition(Point p) override {
    position_ = p;
  }

  Point GetPosition() const override {
    return position_;
  }

  void SetSize(Size size) override {
    size_ = size;
  }

  Size GetSize() const override {
    return size_;
  }

  void SetTexture(std::shared_ptr<ITexture> texture) override{
    texture_ = texture;
  }

  ITexture* GetTexture() const override {
    return texture_.get();
  }
protected:
  Point position_;
  Size size_;
  shared_ptr<ITexture> texture_;
};

bool IsPointInSize(Point p, Size s) {
  return p.x >= 0 && p.y >= 0 && p.x < s.width && p.y < s.height;
}

Size GetImageSize(const Image& image) {
  auto width = static_cast<int>(image.empty() ? 0 : image[0].size());
  auto height = static_cast<int>(image.size());
  return {width, height};
}

class Rectangle: public Shape {
  std::unique_ptr<IShape> Clone() const override {
    return make_unique<Rectangle>(*this);
  }

  void Draw(Image& img) const override {
    for(int y = 0; y < size_.height; y++){
      for(int x = 0; x < size_.width; x++){
        size_t dx = x + position_.x;
        size_t dy = y + position_.y;
        if(dy >= img.size() || dx >= img[0].size()) {
          break;
        }
        char& pixel = img[dy][dx];
        if(texture_ == nullptr){
          pixel = '.';
        }
        else {
          Size img_size = texture_->GetSize();
          if(x < img_size.width && y < img_size.height){
            pixel = texture_->GetImage().at(y).at(x);
          }
          if(x >= img_size.width || y >= img_size.height){
            pixel = '.';
          }
        }
      }
    }
  }

};

class Ellipse: public Shape {
  std::unique_ptr<IShape> Clone() const override {
    return make_unique<Ellipse>(*this);
  }

  void Draw(Image& img) const override {
    Point p = {0,0};
    auto image_size = GetImageSize(img);
    for(p.y = 0; p.y < size_.height; ++p.y){
      for(p.x = 0; p.x < size_.width; ++p.x){
        if(IsInShape(p)){
          char pixel = '.';
          if(texture_ && IsPointInSize(p, texture_->GetSize())){
            pixel = texture_->GetImage()[p.y][p.x];
          }
          Point dp = {position_.x + p.x, position_.y + p.y};
          if (IsPointInSize(dp, image_size)) {
            img[dp.y][dp.x] = pixel;
          }
        }
      }
    }
  }
private:
  bool IsInShape(Point p) const {
    return  IsPointInEllipse({p.x,p.y}, size_);
  }
};

std::unique_ptr<IShape> MakeShape(ShapeType type){
  switch(type){
  case ShapeType::Rectangle:
    return make_unique<Rectangle>();
  case ShapeType::Ellipse:
    return make_unique<Ellipse>();
  }
  return nullptr;
}


class Canvas {
public:
  using ShapeId = size_t;

  void SetSize(Size size) {
    size_ = size;
  }

  ShapeId AddShape(ShapeType shape_type, Point position, Size size,
                   unique_ptr<ITexture> texture) {
    auto shape = MakeShape(shape_type);
    shape->SetPosition(position);
    shape->SetSize(size);
    shape->SetTexture(move(texture));
    return InsertShape(move(shape));
  }

  ShapeId DuplicateShape(ShapeId source_id, Point target_position) {
    auto shape = GetShapeNodeById(source_id)->second->Clone();
    shape->SetPosition(target_position);
    return InsertShape(move(shape));
  }

  void RemoveShape(ShapeId id) {
    shapes_.erase(GetShapeNodeById(id));
  }

  void MoveShape(ShapeId id, Point position) {
    GetShapeNodeById(id)->second->SetPosition(position);
  }

  void ResizeShape(ShapeId id, Size size) {
    GetShapeNodeById(id)->second->SetSize(size);
  }

  int GetShapesCount() const {
    return static_cast<int>(shapes_.size());
  }

  void Print(ostream& output) const {
    Image image(size_.height, string(size_.width, ' '));

    for (const auto& [id, shape] : shapes_) {
      shape->Draw(image);
    }

    output << '#' << string(size_.width, '#') << "#\n";
    for (const auto& line : image) {
      output << '#' << line << "#\n";
    }
    output << '#' << string(size_.width, '#') << "#\n";
  }

private:
  using Shapes = map<ShapeId, unique_ptr<IShape>>;

  Shapes::iterator GetShapeNodeById(ShapeId id) {
    auto it = shapes_.find(id);
    if (it == shapes_.end()) {
      throw out_of_range("No shape with given ID");
    }
    return it;
  }
  ShapeId InsertShape(unique_ptr<IShape> shape) {
    shapes_[current_id_] = move(shape);
    return current_id_++;
  }

  Size size_ = {};
  ShapeId current_id_ = 0;
  Shapes shapes_;
};

void TestSimple() {
  Canvas canvas;
  canvas.SetSize({5, 3});

  canvas.AddShape(ShapeType::Rectangle, {1, 0}, {3, 3}, nullptr);

  stringstream output;
  canvas.Print(output);

  const auto answer =
      "#######\n"
      "# ... #\n"
      "# ... #\n"
      "# ... #\n"
      "#######\n";

  ASSERT_EQUAL(answer, output.str());
}

void TestRectangleOverlap() {
  Canvas canvas;
  canvas.SetSize({5, 3});

  canvas.AddShape(ShapeType::Rectangle, {0, 0}, {6, 5}, nullptr);

  stringstream output;
  canvas.Print(output);

  const auto answer =
      "#######\n"
      "#.....#\n"
      "#.....#\n"
      "#.....#\n"
      "#######\n";

  ASSERT_EQUAL(answer, output.str());
}

void TestEllipseOverlap() {
  Canvas canvas;
  canvas.SetSize({10, 4});

  canvas.AddShape(ShapeType::Ellipse, {0, 0}, {8, 3}, MakeTextureSolid({3,3},'&'));

  stringstream output;
  canvas.Print(output);

  const auto answer =
      "############\n"
      "# &&....   #\n"
      "#&&&.....  #\n"
      "# &&....   #\n"
      "#          #\n"
      "############\n";


  ASSERT_EQUAL(answer, output.str());
}

void TestSmallTexture() {
  Canvas canvas;
  canvas.SetSize({6, 4});

  canvas.AddShape(ShapeType::Rectangle, {1, 1}, {4, 2},
                  MakeTextureSolid({3, 1}, '*'));

  stringstream output;
  canvas.Print(output);

  const auto answer =
      "########\n"
      "#      #\n"
      "# ***. #\n"
      "# .... #\n"
      "#      #\n"
      "########\n";

  ASSERT_EQUAL(answer, output.str());
}

void TestCow() {
  Canvas canvas;
  canvas.SetSize({18, 5});

  canvas.AddShape(ShapeType::Rectangle, {1, 0}, {16, 5}, MakeTextureCow());

  stringstream output;
  canvas.Print(output);

  const auto answer =
      R"(####################)""\n"
      R"(# ^__^             #)""\n"
      R"(# (oo)\_______     #)""\n"
      R"(# (__)\       )\/\ #)""\n"
      R"(#     ||----w |    #)""\n"
      R"(#     ||     ||    #)""\n"
      R"(####################)""\n";

  ASSERT_EQUAL(answer, output.str());
}

void TestCpp() {
  Canvas canvas;
  canvas.SetSize({77, 17});

  canvas.AddShape(ShapeType::Ellipse, {2, 1}, {30, 15},
                  MakeTextureCheckers({100, 100}, 'c', 'C'));
  canvas.AddShape(ShapeType::Ellipse, {8, 4}, {30, 9},
                  MakeTextureSolid({100, 100}, ' '));

  auto h1 = canvas.AddShape(ShapeType::Rectangle, {54, 7}, {22, 3},
                            MakeTextureSolid({100, 100}, '+'));
  auto h2 = canvas.DuplicateShape(h1, {30, 7});

  auto v1 = canvas.DuplicateShape(h1, {62, 3});
  canvas.ResizeShape(v1, {6, 11});
  auto v2 = canvas.DuplicateShape(v1, {38, 3});

  stringstream output;
  canvas.Print(output);

  const auto answer =
      "###############################################################################\n"
      "#                                                                             #\n"
      "#            cCcCcCcCcC                                                       #\n"
      "#        CcCcCcCcCcCcCcCcCc                                                   #\n"
      "#      cCcCcCcCcCcCcCcCcCcCcC          ++++++                  ++++++         #\n"
      "#    CcCcCcCcCcCc                      ++++++                  ++++++         #\n"
      "#   CcCcCcCcC                          ++++++                  ++++++         #\n"
      "#   cCcCcCc                            ++++++                  ++++++         #\n"
      "#  cCcCcC                      ++++++++++++++++++++++  ++++++++++++++++++++++ #\n"
      "#  CcCcCc                      ++++++++++++++++++++++  ++++++++++++++++++++++ #\n"
      "#  cCcCcC                      ++++++++++++++++++++++  ++++++++++++++++++++++ #\n"
      "#   cCcCcCc                            ++++++                  ++++++         #\n"
      "#   CcCcCcCcC                          ++++++                  ++++++         #\n"
      "#    CcCcCcCcCcCc                      ++++++                  ++++++         #\n"
      "#      cCcCcCcCcCcCcCcCcCcCcC          ++++++                  ++++++         #\n"
      "#        CcCcCcCcCcCcCcCcCc                                                   #\n"
      "#            cCcCcCcCcC                                                       #\n"
      "#                                                                             #\n"
      "###############################################################################\n";

  ASSERT_EQUAL(answer, output.str());
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSimple);
  RUN_TEST(tr, TestSmallTexture);
  RUN_TEST(tr, TestRectangleOverlap);
  RUN_TEST(tr, TestEllipseOverlap);
  RUN_TEST(tr, TestCow);
  RUN_TEST(tr, TestCpp);
  return 0;
}
