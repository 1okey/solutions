#include "geo2d.h"
#include "game_object.h"

#include "test_runner.h"

#include <vector>
#include <memory>

using namespace std;

template <typename T>
struct Collider : GameObject {
  bool Collide(const GameObject& that) const final {
    return that.CollideWith(static_cast<const T&>(*this));
  }
};

class Unit final : public Collider<Unit> {
public:
  Unit(geo2d::Point position) : position_(position) {
  }

  geo2d::Point GetPosition() const { return position_; }

  bool CollideWith(const Unit& that) const override;
  bool CollideWith(const Building& that) const override;
  bool CollideWith(const Tower& that) const override;
  bool CollideWith(const Fence& that) const override;

private:
  geo2d::Point position_;
};

class Building final : public Collider<Building> {
public:
  Building(geo2d::Rectangle geometry)
    : geometry_(geometry)
  {
  }

  const geo2d::Rectangle& GetGeometry() const { return geometry_; }

  bool CollideWith(const Unit& that) const override;
  bool CollideWith(const Building& that) const override;
  bool CollideWith(const Tower& that) const override;
  bool CollideWith(const Fence& that) const override;

private:
  geo2d::Rectangle geometry_;
};

class Tower final : public Collider<Tower> {
public:
  Tower(geo2d::Circle geometry)
    : geometry_(geometry)
  {
  }

  const geo2d::Circle& GetGeometry() const { return geometry_; }

  bool CollideWith(const Unit& that) const override;
  bool CollideWith(const Building& that) const override;
  bool CollideWith(const Tower& that) const override;
  bool CollideWith(const Fence& that) const override;

private:
  geo2d::Circle geometry_;
};

class Fence final : public Collider<Fence> {
public:
  Fence(geo2d::Segment geometry)
    : geometry_(geometry)
  {
  }

  const geo2d::Segment& GetGeometry() const { return geometry_; }

  bool CollideWith(const Unit& that) const override;
  bool CollideWith(const Building& that) const override;
  bool CollideWith(const Tower& that) const override;
  bool CollideWith(const Fence& that) const override;

private:
  geo2d::Segment geometry_;
};

// Unit CollideWith implementation

bool Unit::CollideWith(const Unit& that) const {
  return geo2d::Collide(position_, that.position_);
}

bool Unit::CollideWith(const Building& that) const {
  return geo2d::Collide(position_, that.GetGeometry());
}

bool Unit::CollideWith(const Tower& that) const {
  return geo2d::Collide(position_, that.GetGeometry());
}

bool Unit::CollideWith(const Fence& that) const {
  return geo2d::Collide(position_, that.GetGeometry());
}

#define DEFINE_METHOD_COLLIDE_WITH(Class, ArgClass)       \
  bool Class::CollideWith(const ArgClass& that) const {   \
    return geo2d::Collide(geometry_, that.GetGeometry()); \
  }

// Building CollideWith implementation

bool Building::CollideWith(const Unit& that) const {
  return geo2d::Collide(geometry_, that.GetPosition());
}

DEFINE_METHOD_COLLIDE_WITH(Building, Building)
DEFINE_METHOD_COLLIDE_WITH(Building, Tower)
DEFINE_METHOD_COLLIDE_WITH(Building, Fence)

// Tower CollideWith implementation

bool Tower::CollideWith(const Unit& that) const {
  return geo2d::Collide(geometry_, that.GetPosition());
}

DEFINE_METHOD_COLLIDE_WITH(Tower, Building)
DEFINE_METHOD_COLLIDE_WITH(Tower, Tower)
DEFINE_METHOD_COLLIDE_WITH(Tower, Fence)

// Fence CollideWith implementation

bool Fence::CollideWith(const Unit& that) const {
  return geo2d::Collide(geometry_, that.GetPosition());
}

DEFINE_METHOD_COLLIDE_WITH(Fence, Building)
DEFINE_METHOD_COLLIDE_WITH(Fence, Tower)
DEFINE_METHOD_COLLIDE_WITH(Fence, Fence)

bool Collide(const GameObject& first, const GameObject& second) {
  return first.Collide(second);
}

