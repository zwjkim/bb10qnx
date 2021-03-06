/*
 * $QNXLicenseC:
 * Copyright 2007, QNX Software Systems. All Rights Reserved.
 *
 * This source code may contain confidential information of QNX Software
 * Systems (QSS) and its licensors.  Any use, reproduction, modification,
 * disclosure, distribution or transfer of this software, or any software
 * that includes or is based upon any of this code, is prohibited unless
 * expressly authorized by QSS by written agreement.  For more information
 * (including whether this source code file has been published) please
 * email licensing@qnx.com. $
*/

#ifndef __PLAYREADY_DRM_TYPE_H__
#define __PLAYREADY_DRM_TYPE_H__

#include <stdint.h>
#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef uint8_t    DRM_BYTE_t;
typedef char       DRM_CHAR_t;
typedef uint16_t   DRM_WORD_t;
typedef int16_t    DRM_SHORT_t;
typedef uint16_t   DRM_WCHAR_t;
typedef int32_t    DRM_BOOL_t;
typedef uint32_t   DRM_DWORD_t;
typedef uint32_t   DRM_WCHAR32_t;
typedef int32_t    DRM_LONG_t;
typedef uint32_t   DRM_UINT_t;
typedef int32_t    DRM_INT_t;
typedef int64_t    DRM_INT64_t;
typedef uint64_t   DRM_UINT64_t;
typedef void       DRM_VOID_t;
typedef struct    { const DRM_WCHAR_t *pwszString; DRM_DWORD_t cchString; } DRM_CONST_STRING_t;
typedef struct    { DRM_DWORD_t Data1; DRM_WORD_t Data2; DRM_WORD_t Data3; DRM_BYTE_t Data4 [8];} DRM_GUID_t;
typedef struct    { DRM_GUID_t m_oServiceID; DRM_GUID_t m_oAccountID; DRM_DWORD_t m_dwRevision;} DRM_DOMAIN_ID_t;

typedef struct PlayReady PlayReady_t;


typedef enum
{
  epr_DRM_SUCCESS                                          = 0x00000000L, // No error;
  epr_DRM_E_DEVCERTREADERROR                               = 0x8004C045L, // Can't get the device certificate
  epr_DRM_E_SECURESTORE_FULL                               = 0x8004C02BL, // The current secure store key is full. No more data can be added.
  epr_DRM_E_HEADER_NOT_SET                                 = 0x8004C03CL, // The header has not been set with Drm_Content_SetProperty
  epr_DRM_E_LICENSENOTFOUND                                = 0x8004C013L, // A valid license could not be found.
  epr_DRM_E_CRYPTO_FAILED                                  = 0x8004C054L, // A cryptographic operation failed.
  epr_DRM_E_CLK_NOT_SET                                    = 0x8004C05BL, // A license was found but could not be used as the secure clock is not set.
  epr_DRM_E_NO_CLK_SUPPORTED                               = 0x8004C05CL, // The device does not support any clock, and cannot bind to a time-bound license.
  epr_DRM_E_CONDITIONNOTSUPPORTED                          = 0x8004C008L, // A condition in the license found is not supported by this version of DRM.
  epr_DRM_E_INVALIDLICENSE                                 = 0x8004C006L, // A license was found but was invalid.
  epr_DRM_E_LICENSEEXPIRED                                 = 0x8004C009L, // A license was found but has expired, either by depleting the play count or via an end time.
  epr_DRM_E_RIGHTSNOTAVAILABLE                             = 0x8004C00BL, // A license was found, but did not contain the rights the application has requested.
  epr_DRM_E_NO_OPL_CALLBACK                                = 0x8004C06EL, // A license was found which required an OPL callback and none was specified.
  epr_DRM_E_LICEVAL_REQUIRED_REVOCATION_LIST_NOT_AVAILABLE = 0x8004C0C4L, // Failed to update content revocation.
  epr_DRM_E_RIV_TOO_SMALL                                  = 0x8004C063L, // The RIV on the machine is too small.
  epr_DRM_E_INVALID_REVOCATION_LIST                        = 0x8004A018L, // The revocation list version does not match the current revocation version.
  epr_DRM_E_EXTENDED_RESTRICTION_NOT_UNDERSTOOD            = 0x8004A01BL, // An extensible restriction in the license is not understood by the application,and is marked as being required.
  epr_DRM_E_DOMAIN_BIND_LICENSE                            = 0x8004C507L, // Failed to bind to a domain-bound license.
  epr_DRM_E_V1_LICENSE_CHAIN_NOT_SUPPORTED                 = 0x8004C057L, // A V1 header was specified and only a chained license was found.
  epr_DRM_E_CH_BAD_KEY                                     = 0x8004110EL, // The checksum from the content header did not match the decrypted content key."
  epr_DRM_E_LIC_KEY_DECODE_FAILURE                         = 0x80048007L, // An error occurred during decryption of the content key.
  epr_DRM_E_INVALIDARG                                     = 0x80070057L, // A parameter is not valid or is a NULL pointer
  epr_DRM_E_BUFFERTOOSMALL                                 = 0x8007007AL, // The data area passed to a function is too small.
  epr_DRM_E_DSTCORRUPTED                                   = 0x8004C026L, // The data store is corrupted.
  epr_DRM_E_MACHINEIDMISMATCH                              = 0x8004C03eL, // The device has Machine Id different from that in devcert.
  epr_DRM_E_INVALID_SECURESTORE_PASSWORD                   = 0x8004C029L, // The password used to open the secure store key was not able to validate the secure store hash.

  // ***** Begin RIM-specific error codes (Available range 0x8004d200-0x8004dfff) *****
  // libcurl errors
  epr_DRM_E_CURL_ERROR                                     = 0x8004D200L, // An error occurred with the Curl library that is not specified below
  epr_DRM_E_CURL_COULDNT_RESOLVE_HOST                      = 0x8004D201L, // The given remote host was not resolved
  epr_DRM_E_CURL_COULDNT_CONNECT                           = 0x8004D202L, // Failed to connect to host or proxy
  epr_DRM_E_CURL_OPERATION_TIMEDOUT                        = 0x8004D203L, // Operation timeout

  // HTTP errors
  epr_DRM_E_HTTP_ERROR                                     = 0x8004D299L, // Another HTTP error occurred which is not specified below
  epr_DRM_E_HTTP_MULTIPLE_CHOICES                          = 0x8004D300L, // The requested resource has different choices and cannot be resolved into one
  epr_DRM_E_HTTP_MOVED_PERMANENTLY                         = 0x8004D301L, // The requested resource has been assigned a new permanent URI
  epr_DRM_E_HTTP_FOUND                                     = 0x8004D302L, // The requested resource resides temporarily under a different URI
  epr_DRM_E_HTTP_TEMPORARY_REDIRECT                        = 0x8004D307L, // The requested resource resides temporarily under a different URI
  epr_DRM_E_HTTP_BAD_REQUEST                               = 0x8004D400L, // The request could not be understood by the server due to malformed syntax
  epr_DRM_E_HTTP_UNAUTHORIZED                              = 0x8004D401L, // The request requires user authentication
  epr_DRM_E_HTTP_FORBIDDEN                                 = 0x8004D403L, // The server understood the request, but is refusing to fulfill it
  epr_DRM_E_HTTP_NOT_FOUND                                 = 0x8004D404L, // The server has not found anything matching the Request-URI
  epr_DRM_E_HTTP_GONE                                      = 0x8004D410L, // The requested resource is no longer available at the server and no forwarding address is known
  epr_DRM_E_HTTP_INTERNAL_SERVER_ERROR                     = 0x8004D500L, // Internal Server Error
  epr_DRM_E_HTTP_NOT_IMPLEMENTED                           = 0x8004D501L, // The server does not support the functionality required to fulfill the request
  epr_DRM_E_HTTP_SERVICE_UNAVAILABLE                       = 0x8004D503L, // The web server is unable to handle your HTTP request at the time
  epr_DRM_E_HTTP_PERMISSION_DENIED                         = 0x8004D550L, // The account you have currently logged in as does not have permission to perform the action you are attempting.

} DRM_RESULT_t;

#define API_PUBLIC __attribute__ ((visibility ("default")))

/**
* Initialize the PlayReady DRM environment
*
* @param hdl:   the returned DRM handle  on success
* @return DRM_SUCCESS if the call succeeds or an error code
*/
API_PUBLIC DRM_RESULT_t PlayReadyInit( PlayReady_t **hdl );
/**
* Uninitialize the PlayReady DRM environment
*
* @param hdl: a DRM handle return by the PlayreadyInit()
* @return DRM_SUCCESS if the call succeeds or an error code
*/
API_PUBLIC DRM_VOID_t   PlayReadyUninit( PlayReady_t *hdl );
/**
* Set the content Header for the DRM environment
*
* @param hdl:   a DRM handle return by the PlayreadyInit() function
* @param data:  Pointer to the property-specific data
* @param dsize: Count of bytes in the property-specific data
*
* @return DRM_SUCCESS if the call succeeds or an error code
*/
API_PUBLIC DRM_RESULT_t PlayReadyContentSetProperty( PlayReady_t *hdl, const DRM_BYTE_t *data, DRM_DWORD_t dsize );

/**
* Acquire a license from a license server and store
*
* @param hdl:           A DRM handle return by the PlayreadyInit() function
* @param rights         Array of pointers representing the rights that the caller is requesting. iExamples of applicables rights are:
*                       L"None", L"Play", L"CollaborativePlay", L"Print.redbook", L"Copy", L"CreateThumbnailImage", L"Transfer.SDMI",
*                       L"Transfer.NONSDMI", L"Backup", L"PlaylistBurnCount", L"PlaylistBurn",..
* @param pDomainId      pDomainId Pointer to a domain ID. it can be NULL;
* @param customData:    Pointer to a buffer that contains custom data to be sent to the server. It can be NULL.
* @param customDatalen: Size in bytes  of the custom data.
*
* @return DRM_SUCCESS if the call succeeds or an error code
*/
API_PUBLIC DRM_RESULT_t PlayReadyDeviceAcquireLicence(PlayReady_t *hdl, const DRM_CONST_STRING_t **rights, DRM_DWORD_t rightsCount,
        const DRM_DOMAIN_ID_t *pDomainId, DRM_BYTE_t *customData, DRM_DWORD_t customDataLength);


/**
 *  Set the DRM session in verbose mode
 *
 * @param hdl:  DRM handle that was returned from a successfull call to PlayReadyInit
 * @param mode: verbose mode 0 -> off, 1 -> slog, >1  --> stderr
 */
API_PUBLIC DRM_VOID_t   PlayReadyVerboseMode( PlayReady_t *hdl, DRM_DWORD_t mode);

/**
 * Remove license.hds file from device
 *
 * @return DRM_SUCCESS if the call succeeds or an error code
 */
API_PUBLIC DRM_RESULT_t PlayReadyWipeLS(void);


#ifdef __cplusplus
}
#endif
#endif



