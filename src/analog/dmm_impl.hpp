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

#ifndef GENERICDMM_IMPL_HPP
#define GENERICDMM_IMPL_HPP

#include <libm2k/analog/dmm.hpp>
#include <libm2k/analog/enums.hpp>
#include <libm2k/utils/devicein.hpp>
#include <vector>
#include <map>
#include <string>

namespace libm2k {
/**
 * @addtogroup analog
 * @{
 */
namespace analog {

/**
 * @defgroup dmm DMM
 * @brief Contains the representation of the digital multimeter
 * @{
 * @class DMM
 * @brief Controls the digital multimeter
 */
class DMMImpl : public DMM {
public:
	/**
	* @private
	*/
	DMMImpl(struct iio_context *ctx, std::string dev, bool sync);


	/**
	* @private
	*/
	virtual ~DMMImpl();


	/**
	* @private
	*/
	void init();


	/**
	* @brief Retrieve all channels
	*
	* @return A list containing the name of all channels
	*/
	std::vector<std::string> getAllChannels();


	/**
	* @brief Retrieve additional information about the given channel
	*
	* @param index The index corresponding to the channel
	* @return A structure containing additional information
	*/
	libm2k::analog::DMM_READING readChannel(unsigned int index);


	/**
	* @brief Retrieve additional information about the given channel
	*
	* @param chn_name The name corresponding to the channel
	* @return A structure containing additional information
	*/
	libm2k::analog::DMM_READING readChannel(std::string chn_name);


	/**
	* @brief Retrieve additional information about all channels
	*
	* @return A list containing structures for each channel
	*/
	std::vector<libm2k::analog::DMM_READING> readAll();


	/**
	* @brief Retrieve the device's name
	*
	* @return The name of the device
	*/
	std::string getName();

private:
	std::map<std::string, unsigned int> m_channel_id_list;
	std::string m_dev_name;
	std::vector<libm2k::utils::DeviceIn*> m_device_in_list;
	libm2k::utils::DeviceIn *getDevice(int index);
};
}
}



#endif //GENERICDMM_IMPL_HPP
