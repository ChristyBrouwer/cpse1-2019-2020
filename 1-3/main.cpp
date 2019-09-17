#include "hwlib.hpp"

extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s);

extern "C" void application();	

extern "C" char toggle_case(char c){
   if((c>='a') && (c<='z')){
      c-=32;
   }
   else if((c>='A') && (c<='Z')){
      c+=32;
   }
   return c;
}

//123<c>96 64>c<94
int main( void ){	
   
   namespace target = hwlib::target;   
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}