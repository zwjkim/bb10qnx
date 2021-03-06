/*!
 * @copyright
 * Copyright Research In Motion Limited, 2013-2013
 * Research In Motion Limited. All rights reserved.
 */

#ifndef BB_CASCADES_DATAMANAGER_DATAREVISION_HPP_
#define BB_CASCADES_DATAMANAGER_DATAREVISION_HPP_

#include <bb/cascades/datamanager/Global>
#include <bb/cascades/datamanager/Revision>
#include <QSharedPointer>

namespace bb
{
namespace cascades
{
namespace datamanager
{

class DataRevisionPrivate;

/*!
 * @headerfile DataRevision.hpp <bb/cascades/datamanager/DataRevision>
 *
 * @brief Object that encapsulates revision information for some data.
 *
 * It provides a copyable wrapper for a Revision pointer and owns the Revision.
 *
 * It functions much like a shared pointer on an immutable and private Revision
 * object since it will not change the Revision and will delete it when this
 * DataRevision goes out of scope provided that no other DataRevision objects
 * are referencing the Revision.
 *
 * @xmlonly
 * <qml>
 *    <class register="no" />
 * </qml>
 * <apigrouping group="Data Management"/>
 * <library name="bbcascadesdatamanager"/>
 * @endxmlonly
 *
 * @since BlackBerry 10.2.0
 */
class BB_CASCADES_DATAMANAGER_EXPORT DataRevision
{
public:
    /*!
     * @brief Constructor.
     *
     * Note that the Revision will be destroyed when all DataRevision
     * objects that point to it go out of scope.
     *
     * @param rev A pointer to a Revision to be managed. Pointer must not be null.  
     *
     * @since BlackBerry 10.2.0
     */
    explicit DataRevision(Revision* rev);

    /*!
     * @brief Constructor.
     *
     * @since BlackBerry 10.2.0
     */
    DataRevision();

    /*!
     * @brief Copy constructor.
     *
     * Note that the internal Revision will be shared after this copy and
     * will be destroyed when all DataRevision objects that point to it
     * go out of scope.
     *
     * @param other The @c DataRevision object to copy.
     *
     * @since BlackBerry 10.2.0
     */
    DataRevision(const DataRevision& other);

    /*!
     * @brief Assignment operator.
     *
     * @param other The @c DataRevision object to assign from.
     * @return The revised @c DataRevision instance.
     *
     * @since BlackBerry 10.2.0
     */
    DataRevision& operator=(const DataRevision &other);

    /*!
     * @brief Destructor.
     *
     * @since BlackBerry 10.2.0
     */
    virtual ~DataRevision();

    /*!
     * @brief Update this data revision with another one.
     *
     * After the update, this revision must be greater than or equal to both
     * its previous state and @c other.
     *
     * @param other The revision to update this one with.
     *
     * @since BlackBerry 10.2.0
     */
    void update(const DataRevision &other);

    /*!
     * @brief Reset the revision to the "null" state.
     *
     * @since BlackBerry 10.2.0
     */
    void clear();

    /*!
     * @brief Compare whether this revision equals the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if equal and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator==(const DataRevision &other) const;

    /*!
     * @brief Compare whether this revision is greater than (newer than) the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if this revision is newer and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator>(const DataRevision &other) const;

    /*!
     * @brief Compare whether this revision is not equal to the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if not equal and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator!=(const DataRevision &other) const;

    /*!
     * @brief Compare whether this revision is less than (older than) the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if this revision is older and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator<(const DataRevision &other) const;

    /*!
     * @brief Compare whether this revision is less than or equal to (older than or equal to) the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if this revision is older or same age and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator<=(const DataRevision &other) const;

    /*!
     * @brief Compare whether this revision is greater than or equal to (newer than or equal to) the other.
     *
     * @param other The @c DataRevision object to compare with.
     * @return true if this revision is newer or same age and false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool operator>=(const DataRevision &other) const;

    /*!
     * @brief Check whether this revision object contains any revision information.
     *
     * Objects created with the default constructor will initially return true
     * for this method.
     *
     * @return true if the data revision contains no revision information otherwise false.
     *
     * @since BlackBerry 10.2.0
     */
    bool isNull() const;

    /*!
     * @brief String representation of this revision.
     *
     * @return the string representation.
     *
     * @since BlackBerry 10.2.0
     */
    virtual QString toString() const;

private:
    /*! @cond PRIVATE */
    QSharedPointer<Revision> m_revision;
    /*! @endcond */
};

QDebug operator<<(QDebug dbg, const DataRevision &revision);

} // datamanager
} // cascades
} // bb

#endif /* BB_CASCADES_DATAMANAGER_DATAREVISION_HPP_ */
