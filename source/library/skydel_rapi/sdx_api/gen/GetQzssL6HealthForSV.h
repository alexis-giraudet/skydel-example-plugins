#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS L6 health (Health of L6 signal).
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL6HealthForSV;
    typedef std::shared_ptr<GetQzssL6HealthForSV> GetQzssL6HealthForSVPtr;
    
    
    class GetQzssL6HealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetQzssL6HealthForSV();

      GetQzssL6HealthForSV(int svId, const std::optional<std::string>& dataSetName = {});

      static GetQzssL6HealthForSVPtr create(int svId, const std::optional<std::string>& dataSetName = {});
      static GetQzssL6HealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    
  }
}

