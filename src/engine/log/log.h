#pragma once
#include <string>

using String = std::string;

class Log {
  public:
    static void Info(const char* string);
    static void Warn(const char* string);
    static void Error(const char* string);

  private:
    static const String m_InfoPrefix;
    static const String m_WarnPrefix;
    static const String m_ErrorPrefix;
    static void print(const char* message);
    static void print(String prefix, const char* message);
    static void print(const char* message, String postfix);
    static void print(String prefix, const char* message, String postfix);
};