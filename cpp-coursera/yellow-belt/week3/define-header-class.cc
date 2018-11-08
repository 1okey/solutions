PhoneNumber::PhoneNumber(const string &international_number){
  char sign;
  sign = international_number[0];
  if(sign != '+'){
    throw invalid_argument("Number must start with + sign");
  }
  string number = international_number.substr(1, international_number.length() - 1);
  vector<string> fields;
  for(size_t i = 0; i < 3; i++){
    size_t pos = number.find_first_of('-');
    if(i == 2){
      fields.push_back(number.substr(0, number.length()));
    } else if (pos == string::npos){
      fields.push_back("");
    }else {
      fields.push_back(number.substr(0,pos));
      number = number.substr(pos + 1, number.length() - pos);
    }
  }
  if(fields[0].empty() || fields[1].empty() || fields[2].empty()){
    throw invalid_argument("Invalid number format");
  } else {
    country_code_ = fields[0]; city_code_ = fields[1]; local_number_ = fields[2];
  }
}
string PhoneNumber::GetCountryCode() const{
  return country_code_;
}
string PhoneNumber::GetCityCode() const{
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
  return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}

