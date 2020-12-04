const char *detectOS()
{
#if _WIN64
    return "Windows 64-bit";
#elif _WIN32
    return "Windows 32-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
}

void printTime()
{
    time_t current;
    current = time(NULL);
    printf("%s", ctime(&current));
}
