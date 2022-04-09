#include <iostream> // cout, cin, cerr etc...
#include <fstream> // ifstream, ofstream
#include <string>

class Converter
{
private:
    std::ofstream OutStream;
    std::ifstream InStream;

public:
    bool OpenFiles(std::string inFileName, std::string outFileName)
    {
        OutStream = std::ofstream(outFileName); // Creates an output file stream
        if (!OutStream)
        {
            std::cerr << "Canot open " << outFileName << std::endl;
            return false;
        }
        InStream = std::ifstream(inFileName); // Creates an input file stream    
        if (!InStream)
        {
            std::cerr << "Canot open " << inFileName << std::endl;
            CloseFiles();
            return false;
        }

        return true;
    }

    void CloseFiles(void)
    {
        if (OutStream) OutStream.close();
        if (InStream) InStream.close();
    }

    void ProcessLines(void)
    {
        double op1, op2, result;
        char operation;

        while (InStream >> op1 >> operation >> op2)
        {
            OutStream << op1 << " " << operation << " " << op2 << " = ";
            switch (operation)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;            
            case '/':
                result = op1 / op2;
                break;            
            default:
                OutStream << "Illegal Operation" << std::endl;
                continue;
            }

            OutStream << result << std::endl;
        }
    }
};

int main()
{
    Converter myObject = Converter();
    if (myObject.OpenFiles("input.txt", "output.txt") == true)
    {
        myObject.ProcessLines();
        myObject.CloseFiles();
        return 0;
    }
    
    return -1;
}
