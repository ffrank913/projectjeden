#include "log.h"

#include <iostream>

using String = std::string;

const String Log::m_InfoPrefix = "[INFO]: ";
const String Log::m_WarnPrefix = "[WARNING]: ";
const String Log::m_ErrorPrefix = "[ERROR]: ";

void Log::Info(const char* message) {
  Log::print(m_InfoPrefix, message);
}

void Log::Warn(const char* message) {
  Log::print(m_WarnPrefix, message);
}

void Log::Error(const char* message) {
  Log::print(m_ErrorPrefix, message);
}

void print(const char* message) {
  std::cout << message << std::endl;
}

void Log::print(String prefix, const char* message) {
  std::cout << prefix << message << std::endl;
}

void print(const char* message, String postfix) {
  std::cout << message << postfix << std::endl;
}

void Log::print(String prefix, const char* message, String postfix) {
  std::cout << prefix << message << postfix << std::endl;
}