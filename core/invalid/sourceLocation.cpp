#include <iostream>
#include <string_view>
// does not appear...
#include <source_location>

void log(std::string_view message, const std::source_location& location = std::source_location::current()){
    std::cout << "info: " << location.file_name() << ":" << location.line() << " "
              << message << std::endl;
}

int main()
{
    log("Hello world!"); 
    return 1;
}