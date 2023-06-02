
#include "gen/ImportNmeaIntTxTrack.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ImportNmeaIntTxTrack
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ImportNmeaIntTxTrack::CmdName = "ImportNmeaIntTxTrack";
    const char* const ImportNmeaIntTxTrack::Documentation = "Import NMEA interference track file";

    REGISTER_COMMAND_FACTORY(ImportNmeaIntTxTrack);


    ImportNmeaIntTxTrack::ImportNmeaIntTxTrack()
      : CommandBase(CmdName)
    {}

    ImportNmeaIntTxTrack::ImportNmeaIntTxTrack(const std::string& path, const std::string& id)
      : CommandBase(CmdName)
    {

      setPath(path);
      setId(id);
    }

    ImportNmeaIntTxTrackPtr ImportNmeaIntTxTrack::create(const std::string& path, const std::string& id)
    {
      return std::make_shared<ImportNmeaIntTxTrack>(path, id);
    }

    ImportNmeaIntTxTrackPtr ImportNmeaIntTxTrack::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ImportNmeaIntTxTrack>(ptr);
    }

    bool ImportNmeaIntTxTrack::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Path"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ImportNmeaIntTxTrack::documentation() const { return Documentation; }


    int ImportNmeaIntTxTrack::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string ImportNmeaIntTxTrack::path() const
    {
      return parse_json<std::string>::parse(m_values["Path"]);
    }

    void ImportNmeaIntTxTrack::setPath(const std::string& path)
    {
      m_values.AddMember("Path", parse_json<std::string>::format(path, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ImportNmeaIntTxTrack::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ImportNmeaIntTxTrack::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
