//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <fstream>

extern "C++" __declspec(dllimport) bool mergeAndDownsample2x2Images(const std::string & vImage00, const std::string & vImage01, const std::string & vImage10, const std::string & vImage11, const std::string & vOutputImage);
