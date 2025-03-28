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

#ifndef __OPENSPACE_CORE___MISSIONMANAGER___H__
#define __OPENSPACE_CORE___MISSIONMANAGER___H__

#include <openspace/mission/mission.h>

#include <ghoul/misc/assert.h>
#include <ghoul/misc/exception.h>
#include <map>
#include <string>

namespace openspace {

namespace scripting { struct LuaLibrary; }

/**
 * Class keeping track of space missions.
 */
class MissionManager {
public:
    struct MissionManagerException : public ghoul::RuntimeError {
        explicit MissionManagerException(std::string error);
    };

    MissionManager();

    /**
    * Loads the provided mission. If this is the first mission to be loaded, the mission
    * will also be set as the current active mission.
    *
    * \param mission The file that contains the mission that is to be loaded
    * \return The name of the mission that was loaded
    */
    std::string loadMission(Mission mission);

    /**
     * Unloads a previously loaded mission identified by the provided \p missionName.
     *
     * \param missionName The name of the mission that should be unloded
     *
     * \pre \p missionName must be a valid mission that has previously been loaded
     */
    void unloadMission(const std::string& missionName);

    /**
     * Returns whether the provided \p missionName has previously been added to the
     * MissionManager.
     *
     * \param missionName The name of the mission that is to be tested
     * \return `true` if the \p missionName has been added before
     */
    bool hasMission(const std::string& missionName);

    /**
    * Sets the mission with the name \p missionName as the current mission. The current
    * mission is what is return by `currentMission()`.
    *
    * \pre \p missionName must not be empty
    */
    void setCurrentMission(const std::string& missionName);

    /**
     * Returns true if a current mission exists.
     */
    bool hasCurrentMission() const;

    /**
     * Returns the latest mission specified to #setCurrentMission. If no mission has been
     * specified, the first mission loaded will be returned. If no mission has been
     * loaded, a warning will be printed and a dummy mission will be returned.
     */
    const Mission& currentMission();

    /**
     * Returns the mission map.
     */
    const std::map<std::string, Mission>& missionMap();

    static scripting::LuaLibrary luaLibrary();

private:
    std::map<std::string, Mission> _missionMap;
    std::map<std::string, Mission>::iterator _currentMission;
};

} // namespace openspace

#endif // __OPENSPACE_CORE___MISSIONMANAGER___H__
