/*
 * Copyright (c) 2019 Analog Devices Inc.
 *
 * This file is part of libm2k
 * (see http://www.github.com/analogdevicesinc/libm2k).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef M2KHARDWARETRIGGER_IMPL_v024_HPP
#define M2KHARDWARETRIGGER_IMPL_v024_HPP

#include "m2khardwaretrigger_impl.hpp"
//#include <libm2k/m2khardwaretrigger.hpp>
#include <libm2k/enums.hpp>
#include <libm2k/digital/enums.hpp>
#include <libm2k/m2kglobal.hpp>
#include <libm2k/m2k.hpp>
#include "libm2k/utils/channel.hpp"
#include "libm2k/utils/devicein.hpp"
#include <vector>
#include <memory>

using namespace libm2k::utils;
using namespace libm2k::digital;


namespace libm2k {

/**
 * @defgroup m2ktrigger HardwareTrigger
 * @brief Contains the representation of the ADALM2000 trigger system
 * @{
 * @class M2kHardwareTrigger
 * @brief Controls the hardware trigger for ADALM2000
 */
class M2kHardwareTriggerV024Impl : public M2kHardwareTriggerImpl//, public DeviceIn
{
public:
	/**
	 * @private
	 */
	M2kHardwareTriggerV024Impl(struct iio_context *ctx, bool init = true);

	/**
	 * @private
	 */
	virtual ~M2kHardwareTriggerV024Impl();


//	/**
//	 * @private
//	 */
//	void init();

//	/**
//	 * @brief Get the raw analog trigger level for one channel
//	 * @param chnIdx the required channel
//	 * @return the raw analog trigger level
//	 */
//	int getAnalogLevelRaw(unsigned int chnIdx);


//	/**
//	 * @brief Set the raw analog trigger level for one channel
//	 * @param chnIdx the required channel
//	 * @param level the raw analog trigger level
//	 */
//	void setAnalogLevelRaw(unsigned int chnIdx, int level);


//	/**
//	 * @brief Set the analog trigger level for one channel
//	 * @param chnIdx the required channel
//	 * @param v_level the analog trigger level in volts
//	 */
//	void setAnalogLevel(unsigned int chnIdx, double v_level);


//	/**
//	 * @brief Get the analog trigger level for one channel
//	 * @param chnIdx the required channel
//	 * @return the analog trigger level in volts
//	 */
//	double getAnalogLevel(unsigned int chnIdx);


//	/**
//	 * @brief Get the analog hysteresis value for one channel
//	 * @param chnIdx the required channel
//	 * @return the value of the hysteresis in Volts
//	 */
//	double getAnalogHysteresis(unsigned int chnIdx);


//	/**
//	 * @brief Set the analog hysteresis value for one channel
//	 * @param chnIdx the required channel
//	 * @param hysteresis in Volts
//	 */
//	void setAnalogHysteresis(unsigned int chnIdx, double hysteresis);


//	/**
//	 * @brief Get the trigger condition for the analog trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @return the trigger condition
//	 */
//	M2K_TRIGGER_CONDITION_ANALOG getAnalogCondition(unsigned int chnIdx);


//	/**
//	 * @brief Set the trigger condition for the analog trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @param cond the specific trigger condition
//	 */
//	void setAnalogCondition(unsigned int chnIdx, M2K_TRIGGER_CONDITION_ANALOG cond);


//	/**
//	 * @brief Get the trigger condition for the digital trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @return the trigger condition
//	 */
//	M2K_TRIGGER_CONDITION_DIGITAL getDigitalCondition(unsigned int chnIdx);


//	/**
//	 * @brief Set the trigger condition for the digital trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @param cond the specific trigger condition
//	 */
//	void setDigitalCondition(unsigned int chnIdx, M2K_TRIGGER_CONDITION_DIGITAL cond);



//	/**
//	 * @brief Get the mode for the analog trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @return the analog trigger mode
//	 */
//	M2K_TRIGGER_MODE getAnalogMode(unsigned int chnIdx);


//	/**
//	 * @brief Set the mode for the analog trigger on a specific channel
//	 * @param chnIdx the required channel
//	 * @param mode the analog trigger mode
//	 */
//	void setAnalogMode(unsigned int chnIdx, M2K_TRIGGER_MODE mode);


//	/**
//	 * @brief Get the mode for the digital trigger
//	 * @return the digital trigger mode (DIO_OR/DIO_AND)
//	 */
//	libm2k::digital::DIO_TRIGGER_MODE getDigitalMode();


//	/**
//	 * @brief Set the mode for the digital trigger
//	 * @param mode the digital trigger mode (DIO_OR/DIO_AND)
//	 */
//	void setDigitalMode(libm2k::digital::DIO_TRIGGER_MODE mode);


//	/**
//	 * @brief Get the source of the analog trigger
//	 * @return analog trigger source (channel1, channel2, etc)
//	 */
//	M2K_TRIGGER_SOURCE_ANALOG getAnalogSource();


//	/**
//	 * @brief Set the source of the analog trigger
//	 * @param src analog trigger source (channel1, channel2, etc)
//	 */
//	void setAnalogSource(M2K_TRIGGER_SOURCE_ANALOG src);


//	/**
//	 * @brief Get the channel source of the analog trigger
//	 * @return analog trigger channel source (channel1, channel2)
//	 */
//	int getAnalogSourceChannel();


//	/**
//	 * @brief Set the channel source of the analog trigger
//	 * @param chnIdx the index of the channel that should be used
//	 */
//	void setAnalogSourceChannel(unsigned int chnIdx);


//	/**
//	 * @brief Get the analog trigger delay
//	 * @return the value of the delay
//	 *
//	 * @note the delay can have negative values
//	 * The negative values are used to place the trigger inside the buffer
//	 * The value of the delay represents the number of samples in buffer before the triggered sample
//	 * If the value is 0, the triggered sample will be the first one in the buffer
//	 * For a buffer of 1000 samples, in order to have the trigger at the middle, you need to set it to -500
//	 * The minimum negative value is -8192
//	 *
//	 * @note the delay can have positive values
//	 * TBD
//	 */
//	int getAnalogDelay() const;


//	/**
//	 * @brief Set the analog trigger delay
//	 * @param delay the value of the analog delay
//	 *
//	 * @note the delay can have negative values
//	 * The negative values are used to place the trigger inside the buffer
//	 * The value of the delay represents the number of samples in buffer before the triggered sample
//	 * If the value is 0, the triggered sample will be the first one in the buffer
//	 * For a buffer of 1000 samples, in order to have the trigger at the middle, you need to set it to -500
//	 * The minimum negative value is -8192
//	 *
//	 * @note the delay can have positive values
//	 * TBD
//	 */
//	void setAnalogDelay(int delay);


//	/**
//	 * @brief Get the digital trigger delay
//	 * @return the value of the digital delay
//	 *
//	 * @note the delay can have negative values
//	 * The negative values are used to place the trigger inside the buffer
//	 * The value of the delay represents the number of samples in buffer before the triggered sample
//	 * If the value is 0, the triggered sample will be the first one in the buffer
//	 * For a buffer of 1000 samples, in order to have the trigger at the middle, you need to set it to -500
//	 * The minimum negative value is -8192
//	 *
//	 * @note the delay can have positive values
//	 * TBD
//	 */
//	int getDigitalDelay() const;


//	/**
//	 * @brief Set the digital trigger delay
//	 * @param delay the value of the digital delay
//	 *
//	 * @note the delay can have negative values
//	 * The negative values are used to place the trigger inside the buffer
//	 * The value of the delay represents the number of samples in buffer before the triggered sample
//	 * If the value is 0, the triggered sample will be the first one in the buffer
//	 * For a buffer of 1000 samples, in order to have the trigger at the middle, you need to set it to -500
//	 * The minimum negative value is -8192
//	 *
//	 * @note the delay can have positive values
//	 * TBD
//	 */
//	void setDigitalDelay(int delay);


//	/**
//	* @private
//	*/
//	struct SETTINGS *getCurrentHwSettings();


//	/**
//	* @private
//	*/
//	void setHwTriggerSettings(struct SETTINGS *settings);


//	/**
//	 * @brief Set the streaming flag for the analog part
//	 * @param enable the streaming
//	 */
//	void setAnalogStreamingFlag(bool enable);


//	/**
//	 * @brief Get the streaming flag for the analog part
//	 * @return whether the streaming is enabled (true/false)
//	 */
//	bool getAnalogStreamingFlag();


//	/**
//	 * @brief Set the streaming flag for the digital part
//	 * @param enable the streaming
//	 */
//	void setDigitalStreamingFlag(bool enable);


//	/**
//	 * @brief Get the streaming flag for the digital part
//	 * @return whether the streaming is enabled (true/false)
//	 */
//	bool getDigitalStreamingFlag();


//	/**
//	* @private
//	*/
//	static std::vector<std::string> getAvailableDigitalConditions();


//	/**
//	* @private
//	*/
//	void setCalibParameters(unsigned int chnIdx, double scaling, double vert_offset);


//	/**
//	 * @brief getAnalogExternalCondition
//	 * @param chnIdx : integer - the index of the required channel
//	 * @return M2K_TRIGGER_CONDITION_DIGITAL
//	 */
//	M2K_TRIGGER_CONDITION_DIGITAL getAnalogExternalCondition(unsigned int chnIdx);


//	/**
//	 * @brief setAnalogExternalCondition
//	 * @param chnIdx : integer - the index of the required channel
//	 * @param cond : M2K_TRIGGER_CONDITION_DIGITAL
//	 */
//	void setAnalogExternalCondition(unsigned int chnIdx, M2K_TRIGGER_CONDITION_DIGITAL cond);


//	/**
//	 * @brief getDigitalExternalCondition
//	 * @return M2K_TRIGGER_CONDITION_DIGITAL
//	 */
//	M2K_TRIGGER_CONDITION_DIGITAL getDigitalExternalCondition();


//	/**
//	 * @brief setDigitalExternalCondition
//	 * @param cond : M2K_TRIGGER_CONDITION_DIGITAL
//	 */
//	void setDigitalExternalCondition(M2K_TRIGGER_CONDITION_DIGITAL cond);


	/**
	 * @brief Select what should be redirected on the TO (trigger out) pin.
	 *	The options are (none, trigger in, digital in, analog in).
	 * @param output_select : of type M2K_TRIGGER_OUT_SELECT:
	 *	SELECT_TRIGGER_IN - forwards trigger events from TI pin(trigger in);
	 *	SELECT_DIGITAL_IN - forwards trigger events from DigitalIn interface;
	 *      SELECT_ANALOG_IN  - forwards trigger events from AnalogIn interface;
	 *	SELECT_NONE - no trigger event is forwarded;
	 * @note Only available from firmware v0.24.
	 */
	void setAnalogExternalOutSelect(M2K_TRIGGER_OUT_SELECT output_select);


//	/**
//	 * @brief Check which trigger events are forwarded on the TO (trigger out) pin.
//	 * @return M2K_TRIGGER_OUT_SELECT : {SELECT_NONE, SELECT_TRIGGER_IN,
//	 *	SELECT_DIGITAL_IN, SELECT_ANALOG_IN}
//	 * @note Only available from firmware v0.24.
//	 */
//	M2K_TRIGGER_OUT_SELECT getAnalogExternalOutSelect();


//	/**
//	 * @private
//	 */
//	bool hasExternalTriggerIn() const;


//	/**
//	 * @private
//	 */
//	bool hasExternalTriggerOut() const;


//	/**
//	 * @private
//	 */
//	bool hasCrossInstrumentTrigger() const;


//	/**
//	 * @brief Select which interface triggers the DigitalIn.
//	 * @param external_src: of type M2K_TRIGGER_SOURCE_DIGITAL:
//	 *	SRC_TRIGGER_IN - trigger events on the TI(trigger in) pin trigger the DigitalIn interface;
//	 *	SRC_ANALOG_IN - trigger events on the AnalogIn interface trigger the DigitalIn interface;
//	 *	SRC_NONE - trigger events on the DigitalIn are conditioned by the internal digital trigger structure;
//	 * @note Only available from firmware v0.24.
//	 */
//	void setDigitalSource(M2K_TRIGGER_SOURCE_DIGITAL external_src);


//	/**
//	 * @brief Check which is the source of the DigitalIn interface trigger event.
//	 * @return M2K_TRIGGER_SOURCE_DIGITAL : {SRC_TRIGGER_IN, SRC_ANALOG_IN, SRC_NONE}
//	 * @note Only available from firmware v0.24.
//	 */
//	M2K_TRIGGER_SOURCE_DIGITAL getDigitalSource() const;

//	M2K_TRIGGER_CONDITION_DIGITAL getDigitalCondition(DIO_CHANNEL chn);
//	void setDigitalCondition(DIO_CHANNEL chn, M2K_TRIGGER_CONDITION_DIGITAL cond);
//private:
//	struct iio_device *m_trigger_device;
//	std::vector<Channel *> m_analog_channels;
//	std::vector<Channel *> m_digital_channels;
//	std::vector<Channel *> m_logic_channels;
//	std::shared_ptr<DeviceIn> m_digital_trigger_device;

//	Channel *m_delay_trigger;
//	bool m_streaming_flag_digital;
//	bool m_streaming_flag_analog;

//	unsigned int m_num_channels;
//	std::vector<bool> m_analog_enabled;
//	std::vector<bool> m_digital_enabled;
//	std::vector<double> m_scaling, m_offset;

//	double m_firmware_version;

//	static std::vector<std::string> m_trigger_analog_cond;
//	static std::vector<std::string> m_trigger_digital_cond;
//	static std::vector<std::string> m_trigger_mode;
//	static std::vector<std::string> m_trigger_source;
//	static std::vector<std::string> m_trigger_logic_mode;
private:
	static std::vector<std::string> m_digital_out_select;
	static std::vector<std::string> m_digital_out_direction;
};
}

#endif //M2KHARDWARETRIGGER_IMPL_v024_HPP
