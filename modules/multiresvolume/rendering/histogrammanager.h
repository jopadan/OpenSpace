/*****************************************************************************************
 *                                                                                       *
 * OpenSpace                                                                             *
 *                                                                                       *
 * Copyright (c) 2014-2025                                                               *
 *                                                                                       *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this  *
 * software and associated documentation files (the "Software"), to deal in the Software *
 * without restriction, including without limitation the rights to use, copy, modify,    *
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to    *
 * permit persons to whom the Software is furnished to do so, subject to the following   *
 * conditions:                                                                           *
 *                                                                                       *
 * The above copyright notice and this permission notice shall be included in all copies *
 * or substantial portions of the Software.                                              *
 *                                                                                       *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,   *
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A         *
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT    *
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF  *
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE  *
 * OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                                         *
 ****************************************************************************************/

#ifndef __OPENSPACE_MODULE_MULTIRESVOLUME___HISTOGRAMMANAGER___H__
#define __OPENSPACE_MODULE_MULTIRESVOLUME___HISTOGRAMMANAGER___H__

#include <openspace/util/histogram.h>
#include <filesystem>

namespace openspace {

class TSP;

class HistogramManager {
public:
    bool buildHistograms(TSP* tsp, int numBins);
    Histogram* histogram(unsigned int brickIndex);
    bool loadFromFile(const std::filesystem::path& filename);
    bool saveToFile(const std::filesystem::path& filename);

private:
    bool buildHistogram(TSP* tsp, unsigned int brickIndex);
    std::vector<float> readValues(TSP* tsp, unsigned int brickIndex);

    std::vector<Histogram> _histograms;
    float _minBin = 0.f;
    float _maxBin = 0.f;
    int _numBins = 0;
};

} // namespace openspace

#endif // __OPENSPACE_MODULE_MULTIRESVOLUME___HISTOGRAMMANAGER___H__
