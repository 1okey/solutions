// Implement function ToLowerCase() that has a string parameter 
// str, and returns the same string in lowercase.
//
//Example 1:
//
//Input: "Hello"
//Output: "hello"
//
//Example 2:
//
//Input: "here"
//Output: "here"
//
//Example 3:
//Output: "lovely"

char* toLowerCase(char* str) {
  char * ptr = str;
  while(*ptr != 0){
    *ptr |= 0x20;
    ++ptr;
  }
  return str;
}


