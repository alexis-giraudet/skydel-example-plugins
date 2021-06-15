#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGpsL5HealthForSVResult
///
#include "gen/GetGpsL5HealthForSVResult.h"

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGpsL5HealthForSVResult::CmdName = "GetGpsL5HealthForSVResult";
    const char* const GetGpsL5HealthForSVResult::Documentation = "Result of GetGpsL5HealthForSV.";

    REGISTER_COMMAND_RESULT_FACTORY(GetGpsL5HealthForSVResult);


    GetGpsL5HealthForSVResult::GetGpsL5HealthForSVResult()
      : CommandResult(CmdName)
    {}

    GetGpsL5HealthForSVResult::GetGpsL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health)
      : CommandResult(CmdName, relatedCommand)
    {

      setSvId(svId);
      setHealth(health);
    }


    GetGpsL5HealthForSVResultPtr GetGpsL5HealthForSVResult::create(CommandBasePtr relatedCommand, int svId, bool health)
    {
      return GetGpsL5HealthForSVResultPtr(new GetGpsL5HealthForSVResult(relatedCommand, svId, health));
    }

    GetGpsL5HealthForSVResultPtr GetGpsL5HealthForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGpsL5HealthForSVResult>(ptr);
    }

    bool GetGpsL5HealthForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<bool>::is_valid(m_values["Health"])
        ;

    }

    std::string GetGpsL5HealthForSVResult::documentation() const { return Documentation; }


    int GetGpsL5HealthForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetGpsL5HealthForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetGpsL5HealthForSVResult::health() const
    {
      return parse_json<bool>::parse(m_values["Health"]);
    }

    void GetGpsL5HealthForSVResult::setHealth(bool health)
    {
      m_values.AddMember("Health", parse_json<bool>::format(health, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
