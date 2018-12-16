#pragma once

// Ð—Ð´ÐµÑÑŒ Ð±ÑƒÐ´ÐµÑ‚ Ð¿Ð¾Ð´ÐºÐ»ÑŽÑ‡Ñ‘Ð½ Ð²Ð°Ñˆ Ñ„Ð°Ð¹Ð»
#include "booking.h"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

class FlightProvider {
public:
  using BookingId = int;
  using Booking = FlightBooking;

  struct BookingData {
    string city_from;
    string city_to;
    string date;
  };

  Booking Book(const BookingData& data) {
    if (counter >= capacity) {
      throw runtime_error("Flight overbooking");
    }
    ++counter;
    return {this, counter};
  }

  void Cancel(const Booking& booking) {
    --counter;
  }

public:
  static int capacity;
  static int counter;
};


class HotelProvider {
public:
  using BookingId = int;
  using Booking = HotelBooking;

  struct BookingData {
    string city;
    string date_from;
    string date_to;
  };

  Booking Book(const BookingData& data) {
    if (counter >= capacity) {
      throw runtime_error("Hotel overbooking");
    }
    ++counter;
    return {this, counter};
  }

  void Cancel(const Booking& booking) {
    --counter;
  }

public:
  static int capacity;
  static int counter;
};
