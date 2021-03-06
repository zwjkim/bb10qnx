/*!
 * @copyright
 * Copyright Research In Motion Limited, 2013-2013
 * Research In Motion Limited. All rights reserved.
 */

#ifndef BB_DEVICE_MIRACASTDEVICECATEGORY_HPP
#define BB_DEVICE_MIRACASTDEVICECATEGORY_HPP

#include <bb/device/Global>

#include <QObject>
#include <QtDeclarative/QtDeclarative>

namespace bb
{
namespace device
{

/*!
 * @headerfile MiracastDeviceCategory.hpp <bb/device/MiracastDeviceCategory>
 *
 * @brief Indicates the primary category of the Miracast device.
 *
 * @details The categories here are taken from the Wi-Fi Peer-to-Peer (P2P) Technical
 * Specification, version 1.2, section B2, table B1.
 *
 * @xmlonly
 * <apigrouping group="Device and Communication/Control"/>
 * <library name="bbdevice"/>
 * <qml>
 *    <class register="enum-only" />
 * </qml>
 * @endxmlonly 
 *
 * @since BlackBerry 10.2.0
 */
class BB_DEVICE_EXPORT MiracastDeviceCategory
{
    Q_GADGET
    Q_ENUMS(Type)

public:
    /*!
     * @brief Indicates the primary category of the Miracast device.
     *
     * @since BlackBerry 10.2.0
     */
    enum Type
    {
        /*!
         * @brief The type of device could not be determined.
		 *
		 * @since BlackBerry 10.2.0
         */
        Unknown = 0,

        /*!
         * @brief The device is identified as a computer.
		 *
		 * @since BlackBerry 10.2.0
         */
        Computer = 1,

        /*!
         * @brief The device is identified as an input device.
		 *
		 * @since BlackBerry 10.2.0
         */
        Input = 2,

        /*!
         * @brief The device is identified as a Printer, Copier, Fax or Scanner.
		 *
		 * @since BlackBerry 10.2.0
         */
        PrinterCopierFaxOrScanner = 3,

        /*!
         * @brief The device is identified as a camera.
		 *
		 * @since BlackBerry 10.2.0
         */
        Camera = 4,

        /*!
         * @brief The device is identified as a storage device.
		 *
		 * @since BlackBerry 10.2.0
         */
        Storage = 5,

        /*!
         * @brief The device is identified as a network infrastructure device.
		 *
		 * @since BlackBerry 10.2.0
         */
        NetworkInfrastructure = 6,

        /*!
         * @brief The device is identified as a display.
		 *
		 * @since BlackBerry 10.2.0
         */
        Display = 7,

        /*!
         * @brief The device is identified as a multimedia device.
		 *
		 * @since BlackBerry 10.2.0
         */
        Multimedia = 8,

        /*!
         * @brief The device is identified as a gaming device.
		 *
		 * @since BlackBerry 10.2.0
         */
        Gaming = 9,

        /*!
         * @brief The device is identified as a telephone.
		 *
		 * @since BlackBerry 10.2.0
         */
        Telephone = 10,

        /*!
         * @brief The device is identified as an audio device.
		 *
		 * @since BlackBerry 10.2.0
         */
        Audio = 11,

        /*!
         * @brief The device is identified, but does not fit in to any of the other categories.
		 *
		 * @since BlackBerry 10.2.0
         */
        Other = 12

    };

private:
    //!@cond PRIVATE
    MiracastDeviceCategory();
    ~MiracastDeviceCategory();
    //!@endcond
};

} // namespace device
} // namespace bb

QML_DECLARE_TYPE(bb::device::MiracastDeviceCategory)
#endif // BB_DEVICE_MIRACASTDEVICECATEGORY_HPP
