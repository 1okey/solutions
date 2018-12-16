#include <memory>
using namespace std;

class FlightProvider;
class HotelProvider;

template<typename Provider>
struct ProviderBooking{
  ProviderBooking(Provider* ptr, int& counter)
    :provider_(ptr), counter_(counter)
  {
    if(Provider::counter > Provider::capacity){
      throw runtime_error("Flights are overbooked!");
    }
    Provider::counter++;
  }

  ~ProviderBooking(){
    if(Provider::counter > 0){
      provider_->Cancel(*this);
    }
  }
  Provider* provider_;
  int& counter_;
};

using FlightBooking = ProviderBooking<FlightProvider>;
using HotelBooking = ProviderBooking<HotelProvider>;
