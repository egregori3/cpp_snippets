ParseTemplate::ParseTemplate(std::string_view TemplateFilename)
{
    std::cout << "Opening template file: " << TemplateFilename << std::endl;
    TemplateStream = std::ifstream(std::string(TemplateFilename));
    TemplateString.assign((std::istreambuf_iterator<char>(TemplateStream)), std::istreambuf_iterator<char>());
}
