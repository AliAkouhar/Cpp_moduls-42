#include <iostream>
#include <string>

int main()
{
    std::string cmd;
    while (1)
    {
        std::cout << " enter a command\n";
        std::cin >> cmd;
        if (cmd.empty())
            return (1);
        std::cout << cmd << std::endl;
    }
}
//     Contact obj;

//     obj.SetFirstName("ali");
//     obj.SetLastName("akouhar");
//     std::cout << obj.GetFirstName() << " "<< obj.GetLastName() << std::endl;

 