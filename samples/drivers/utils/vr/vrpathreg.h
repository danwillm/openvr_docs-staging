#pragma once

#include <string>

bool RegisterDriverWithRuntime(const std::string &driver_path);

bool RemoveDriverFromRuntime(const std::string &driver_path);