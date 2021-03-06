/*!
 * @copyright
 * Copyright Research In Motion Limited, 2012-2013
 * Research In Motion Limited. All rights reserved.
 */

#ifndef MARKORDELETEPRIOROP_HPP_
#define MARKORDELETEPRIOROP_HPP_

#include <bb/pim/Global>

namespace bb {
namespace pim {
namespace message {

class BB_PIM_EXPORT MarkOrDeletePriorOp{
public:
    /*!
     * @brief An enumeration of supported Prior to Date operations for messages.
     *
     * @since BlackBerry 10.0.0
     */
    enum Type {
        /*!
        * @brief Indicates Mark all messages prior to given date as read.
         *
         * @since BlackBerry 10.0.0
        */
        MarkPriorRead=0,
        /*!
        * @brief Indicates Mark all messages prior to give date as unread.
         *
         * @since BlackBerry 10.0.0
        */
        MarkPriorUnread = 1,
        /* @brief Indicates Delete all messages prior to given date.
         *
         * @since BlackBerry 10.0.0
        */
        DeletePrior = 2,
    };

private:
    MarkOrDeletePriorOp();
    ~MarkOrDeletePriorOp();
};

} /* namespace message */
} /* namespace pim */
} /* namespace bb */
#endif /* MARKORDELETEPRIOROP_HPP_ */
