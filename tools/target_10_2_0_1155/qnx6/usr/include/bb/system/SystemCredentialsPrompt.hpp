/*!
 * @copyright
 * Copyright Research In Motion Limited, 2012-2013
 * Research In Motion Limited. All rights reserved.
 */

#ifndef  BB_SYSTEM_SYSTEMCREDENTIALSPROMPT_HPP
#define  BB_SYSTEM_SYSTEMCREDENTIALSPROMPT_HPP

#include <bb/system/Global>
#include <bb/system/SystemUiButton>
#include <bb/system/SystemUiInputField>
#include <bb/system/SystemUiModality>
#include <bb/system/SystemUiReturnKeyAction>
#include <bb/system/SystemUiError>
#include <bb/system/SystemUiResult>

#include <QObject>
#include <QScopedPointer>
#include <QtDeclarative/QtDeclarative>

namespace bb
{
namespace system
{

class SystemCredentialsPromptPrivate;

/*!
 * @headerfile SystemCredentialsPrompt.hpp <bb/system/SystemCredentialsPrompt>
 *
 * @brief A dialog box that asks the user for login credentials.
 *
 * @details The displayed prompt will be an application-modal window.
 *
 * Presentation properties are marked as such, and affect future requests.
 * Any pending requests will use the values of the presentation properties at the time of the request.
 *
 * <B>Note:</B> Once the dialog is displayed after a call to @c show() or @c exec() there are two ways of updating the dialog after changing its presentation properties.
 *
 * The default way is to update all the necessary presentation properties and call the @c update() method.
 * This guarantees that all the presentation properties will be updated at the same time.
 *
 * The second method is to have the dialog update automatically after every presentation property change. To enable these automatic updates,
 * the @c autoUpdateEnabled property must be set to @c true.
 *
 * Be aware that the second method does not guarantee atomic updates for all the presentation properties changes.
 * This method can lead to noticeable delays between updates of individual properties. If more than one property needs to be updated, use the first method.
 * If only one presentation property is being updated frequently
 * (for example the text on the dialog @c body must be updated to notify the user of the application's current status)
 * the second approach can be used.
 *
 * @xmlonly
 * <apigrouping group="User Interface/System UI"/>
 * <library name="bbsystem"/>
 * <qml>
 *    <class register="yes" />
 * </qml>
 * @endxmlonly
 *
 * @since BlackBerry 10.0.0
 */
class BB_SYSTEM_EXPORT SystemCredentialsPrompt : public QObject
{
    Q_OBJECT

    /*!
     * @brief Represents the title of the window.
     * @details This is a presentation property whose default value is a default-constructed @c QString.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(QString title READ title WRITE setTitle RESET resetTitle NOTIFY titleChanged FINAL)

    /*!
     * @brief Represents the main text of the window.
     * @details This is a presentation property whose default value is a default-constructed @c QString.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(QString body READ body WRITE setBody RESET resetBody NOTIFY bodyChanged FINAL)

    /*!
     * @brief Represents a message to be shown to the user when invalid credentials are entered.
     * @details This property should be combined with setting @c dismissAutomatically to false so that the prompt is updated while being displayed to the user.
     *
     * This is a presentation property whose default value is a default-constructed @c QString.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(QString validationMessage READ validationMessage WRITE setValidationMessage RESET resetValidationMessage NOTIFY validationMessageChanged FINAL)

    /*!
     * @brief Controls whether or not the text should be displayed with emoticons.
     * @details This is a presentation property whose default value is @c false.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bool emoticonsEnabled READ emoticonsEnabled WRITE setEmoticonsEnabled RESET resetEmoticonsEnabled NOTIFY emoticonsEnabledChanged FINAL)

    /*!
     * @brief Indicates whether a toggle switch for displaying the password in cleartext should be included.
     * @details This is a presentation property whose default value is @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bool includeShowPassword READ includeShowPassword WRITE setIncludeShowPassword RESET resetIncludeShowPassword NOTIFY includeShowPasswordChanged FINAL)

    /*!
     * @brief Indicates whether a toggle switch for remembering password credentials should be included.
     * @details If a toggle switch is requested, then the user will have the ability to enable and disable it.
     * The user selection will be available using @c rememberMeSelection() when the request is finished.
     * To customize how the toggle switch is presented, use @c rememberMeChecked and @c rememberMeText.
     *
     * This is a presentation property whose default value is @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bool includeRememberMe READ includeRememberMe WRITE setIncludeRememberMe RESET resetIncludeRememberMe NOTIFY includeRememberMeChanged FINAL)

    /*!
     * @brief Indicates whether the dialog will be udpated every time a presentation property is changed.
     * @details If @c autoUpdateEnabled is @c true, every time any of the presentation properties on the dialog are changed,
     * the dialog will also update immediately to reflect the changes on the UI. If @c autoUpdateEnabled is @c false, the dialog
     * will not update automatically, instead the @c show() method must be called. This is the default behavior.
     *
     * @note The main difference in behavior with the @c autoUpdateEnabled flag is most apparent when multiple presentation properties are changed.
     * With @c autoUpdateEnabled set to @c true, the onscreen dialog may be updated after each individual presentation property is changed.
     * This may not be an ideal user experience, particularly as the number of changed presentation properties increases.
     * With @c autoUpdateEnabled set to @c false, it is possible to batch multiple presentation property updates and apply them
     * to the onscreen dialog as one unit by calling @c show().
     *
     * @since BlackBerry 10.2.0
     */
    Q_PROPERTY(bool autoUpdateEnabled READ isAutoUpdateEnabled WRITE setAutoUpdateEnabled RESET resetAutoUpdateEnabled NOTIFY autoUpdateEnabledChanged REVISION 1)

    /*!
     * @brief Represents the selection state of the toggle switch for remembering password credentials.
     * @details The state is only applied if @c includeRememberMe is @c true.
     *
     * The user selection will be available using @c rememberMeSelection() when the request is finished.
     *
     * This is a presentation property whose default value is @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bool rememberMeChecked READ rememberMeChecked WRITE setRememberMeChecked RESET resetRememberMeChecked NOTIFY rememberMeCheckedChanged FINAL)

    /*!
     * @brief Represents the text associated with the toggle switch associated with @c rememberMeChecked.
     * @details This property is only applied if @c includeRememberMe is @c true.
     *
     * This is a presentation property whose default value is @c "Remember Me".
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(QString rememberMeText READ rememberMeText WRITE setRememberMeText RESET resetRememberMeText NOTIFY rememberMeTextChanged FINAL)

    /*!
     * @brief The maximum number of buttons that can be shown without causing an overflow.
     * @details When overflow occurs all buttons will be stacked vertically.
     *
     * This is a presentation property whose default value is -1.
     * @note -1 implies that default system behavior will be applied. The supported range is 1-3, with any values outside the range resetting the property to its default value.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(int buttonAreaLimit READ buttonAreaLimit WRITE setButtonAreaLimit RESET resetButtonAreaLimit NOTIFY buttonAreaLimitChanged FINAL)

    /*!
     * @brief Indicates whether to dismiss the prompt when a button is selected.
     * @details If @c false, the prompt must be dismissed using @c cancel(). Otherwise, the dialog box is dismissed on a button press
     *
     * This is a presentation property whose default value is @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bool dismissAutomatically READ dismissAutomatically WRITE setDismissAutomatically RESET resetDismissAutomatically NOTIFY dismissAutomaticallyChanged FINAL)

    /*!
     * @brief Indicates whether to display an activity indicator in the title bar of the dialog.
     *
     * This is a presentation property whose default value is @c false.
     *
     * @since BlackBerry 10.2.0
     */
    Q_PROPERTY(bool activityIndicatorVisible READ activityIndicatorVisible WRITE setActivityIndicatorVisible RESET resetActivityIndicatorVisible NOTIFY activityIndicatorVisibleChanged REVISION 1)

    /*!
     * @brief Represents the action associated with the return key for this prompt.
     * @details This a presentation property whose default value is @c bb::system::SystemUiReturnKeyAction::Default.
     * @see @c bb::system::SystemUiReturnKeyAction for the list of possible values.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bb::system::SystemUiReturnKeyAction::Type returnKeyAction READ returnKeyAction WRITE setReturnKeyAction RESET resetReturnKeyAction NOTIFY returnKeyActionChanged FINAL)

    /*!
     * @brief Represents the modality of the prompt.
     * @details This is a presentation property whose value is @c bb::system::SystemUiModality::Application.
     * @see @c bb::system::SystemUiModality for the list of valid values.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bb::system::SystemUiModality::Type modality READ modality WRITE setModality RESET resetModality NOTIFY modalityChanged FINAL)

    /*!
     * @brief Represents the username field that will be included in the window.
     * @details This is a presentation property whose default @c bb::system::SystemUiInputField::emptyText property is @c "Username".
     *
     * @note @c bb::system::SystemUiInputField::maximumLength is ignored.
     *
     * @since BlackBerry 10.0.0
     *
     * @xmlonly
     * <qml>
     * <property groupedProperty="yes"/>
     * </qml>
     * @endxmlonly
     */
    Q_PROPERTY(bb::system::SystemUiInputField* usernameField READ usernameField RESET resetUsernameField FINAL)

    /*!
     * @brief Represents the password field that will be included in the window.
     * @details This is a presentation property whose default @c bb::system::SystemUiInputField::emptyText property is @c "Password".
     *
     * @note @c bb::system::SystemUiInputField::maximumLength is ignored.
     *
     * @since BlackBerry 10.0.0
     *
     * @xmlonly
     * <qml>
     * <property groupedProperty="yes"/>
     * </qml>
     * @endxmlonly
     */
    Q_PROPERTY(bb::system::SystemUiInputField* passwordField READ passwordField RESET resetPasswordField FINAL)

    /*!
     * @brief Represents the button associated with the default confirmation action of the window.
     *
     * @details This is a presentation property whose default @c bb::system::SystemUiButton::label property is @c "Login".
     *
     * @since BlackBerry 10.0.0
     *
     * @xmlonly
     * <qml>
     * <property groupedProperty="yes"/>
     * </qml>
     * @endxmlonly
     */
    Q_PROPERTY(bb::system::SystemUiButton* confirmButton READ confirmButton RESET resetConfirmButton FINAL)

    /*!
     * @brief Represents the button associated with the tertiary action of the window.
     *
     * @details This is a presentation property whose default @c bb::system::SystemUiButton::label property is a default-constructed @c QString.
     *
     * @note This button is omitted if its @c bb::system::SystemUiButton::label property is a default-constructed @c QString.
     *
     * @since BlackBerry 10.0.0
     *
     * @xmlonly
     * <qml>
     * <property groupedProperty="yes"/>
     * </qml>
     * @endxmlonly
     */
    Q_PROPERTY(bb::system::SystemUiButton* customButton READ customButton RESET resetCustomButton FINAL)

    /*!
     * @brief Represents the button associated with the default canceling action of the window.
     *
     * @details This is a presentation property whose default @c bb::system::SystemUiButton::label property is @c "Cancel".
     *
     * @since BlackBerry 10.0.0
     *
     * @xmlonly
     * <qml>
     * <property groupedProperty="yes"/>
     * </qml>
     * @endxmlonly
     */
    Q_PROPERTY(bb::system::SystemUiButton* cancelButton READ cancelButton RESET resetCancelButton FINAL)

    /*!
     * @brief Represents the button associated with the return key action of the window.
     * @details When the user triggers the return key action, this button will be automatically selected.
     * If the @c defaultButton is @c NULL, then triggering the return key action will not select any button.
     *
     * If @c defaultButton is set to a button that this instance does not manage, then this property is undefined.
     *
     * This is a presentation property whose default value is @c confirmButton.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bb::system::SystemUiButton* defaultButton READ defaultButton WRITE setDefaultButton RESET resetDefaultButton NOTIFY defaultButtonChanged FINAL)

    /*!
     * @brief Represents the result of the last completed request.
     * @details To obtain result values once the request is finished, use the following functions:
     * - @c result() - the result of the request
     * - @c error() - the error that occurred during the request (if applicable)
     * - @c buttonSelection() - the button selected (if applicable)
     * - @c usernameEntry() - the username entered by the user (if applicable)
     * - @c passwordEntry() - the password entered by the user (if applicable)
     * - @c rememberMeSelection() - the user preference as to whether the result should be remembered (if applicable)
     *
     * @see @c bb::system::SystemUiResult for the list of possible results.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bb::system::SystemUiResult::Type result READ result NOTIFY finished FINAL)

    /*!
     * @brief Represents the last error encountered.
     * @details This property is only valid when the @c SystemCredentialsPrompt::result property is @c bb::system::SystemUiResult::Error.
     * @see @c bb::system::SystemUiError for the list of possible errors.
     *
     * @since BlackBerry 10.0.0
     */
    Q_PROPERTY(bb::system::SystemUiError::Type error READ error FINAL)

public:
    /*!
     * @brief Constructs a new instance of a credentials prompt.
     * @param parent If not 0, the supplied parent will be responsible for deleting this instance.
     *
     * @since BlackBerry 10.0.0
     */
    explicit SystemCredentialsPrompt(QObject* parent = 0);

    /*!
     * @brief Destroys the credentials prompt, canceling any pending requests.
     *
     * @since BlackBerry 10.0.0
     */
    virtual ~SystemCredentialsPrompt();

    /*!
     * @brief Retrieves the title for the prompt.
     * @return The title of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    QString title() const;

    /*!
     * @brief Retrieves the main text of the prompt.
     * @return The text of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    QString body() const;

    /*!
     * @brief Retrieves the validation message of the prompt.
     * @return The validation message of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    QString validationMessage() const;

    /*!
     * @brief Retrieves whether the text can be displayed as emoticons.
     * @return Whether the prompt supports emoticons.
     *
     * @since BlackBerry 10.0.0
     */
    bool emoticonsEnabled() const;

    /*!
     * @brief Retrieves the username input field for the prompt.
     * @details This instance retains ownership of the returned value.
     * @return The prompt's username input field.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiInputField* usernameField();

    /*!
     * @brief Retrieves the password input field for the prompt.
     * @details This instance retains ownership of the returned value.
     * @return The prompt's password input field.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiInputField* passwordField();

    /*!
     * @brief Retrieves the flag indicating if a toggle switch that can reveal the password field should be included in the prompt.
     * @return @c true if a toggle for revealing the password should be included in the prompt, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    bool includeShowPassword() const;

    /*!
     * @brief Retrieves the flag indicating if a toggle switch to remember the credentials should be included in the prompt.
     * @return @c true if a toggle for remembering the entered credentials should be included in the prompt, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    bool includeRememberMe() const;

    /*!
     * @brief Retrieves the flag indicating if the dialog will be updated every time the value of a presentation property is changed.
     * @return @c true if the dialog automatically updates, @c false if the dialog doesn't update (in which case the @c show() method
     * must be called after updating the dialog presentation properties).
     *
     * @since BlackBerry 10.2.0
     */
    bool isAutoUpdateEnabled() const;

    /*!
     * @brief Retrieves whether the toggle switch for @c includeRememberMe will be selected by default.
     * @details To obtain the user selection, use @c rememberMeSelection() instead.
     * @return @c true if the toggle should be selected by default, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    bool rememberMeChecked() const;

    /*!
     * @brief Retrieves the text associated with the toggle switch for @c includeRememberMe.
     * @return The text for the toggle for @c includeRememberMe.
     *
     * @since BlackBerry 10.0.0
     */
    QString rememberMeText() const;

    /*!
     * @brief Retrieves the prompt's confirmation button.
     * @details This instance retains ownership of the returned value.
     * @return The prompt's confirmation button.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiButton* confirmButton();

    /*!
     * @brief Retrieves the button attached to the prompt's custom action button.
     * @details This instance retains ownership of the returned value.
     * @return The prompt's custom action button.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiButton* customButton();

    /*!
     * @brief Retrieves the prompt's cancel button.
     * @details This instance retains ownership of the returned value.
     * @return The prompt's cancellation button.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiButton* cancelButton();

    /*!
     * @brief Retrieves the prompt's default button.
     * @details This instance retains ownership of the returned value.
     *
     * The default button is automatically selected when the user triggers the return key action.
     * If the default button is @c NULL, no button will be automatically selected.
     *
     * The returned value will be one of the buttons managed by this instance, or @c NULL.
     * @return The prompt's default button.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiButton* defaultButton();

    /*!
     * @brief Retrieves the maximum number of buttons to accommodate in the prompt button area without causing overflow.
     * @details If @c buttonAreaLimit is larger than the number of buttons that will be displayed, all buttons will be stacked vertically.
     * @return The limit for the number of buttons that can be accommodated in the button area, or -1 if system defaults should be used.
     *
     * @since BlackBerry 10.0.0
     */
    int buttonAreaLimit() const;

    /*!
     * @brief Indicates if the prompt is dismissed when a button is selected.
     * @return @c true if selecting a button dismisses the prompt, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    bool dismissAutomatically() const;

    /*!
     * @brief Indicates if an activity indicator is displayed on the title bar of the dialog.
     * @return @c true if the activity indicator is displayed, @c false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    bool activityIndicatorVisible() const;

    /*!
     * @brief Retrieves the prompt's return key action.
     * @return The prompt's return key action.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiReturnKeyAction::Type returnKeyAction() const;

    /*!
     * @brief Retrieves the prompt's modality.
     * @return The prompt's modality.  See @c bb::system::SystemUiModality for the list of possible values.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiModality::Type modality() const;

    /*!
     * @brief Sets the title for the prompt.
     * @param title The new title of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    void setTitle(const QString& title);

    /*!
     * @brief Sets the main text of the prompt.
     * @param body The new text of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    void setBody(const QString& body);

    /*!
     * @brief Sets the validation message of the prompt.
     * @details This can be combined with setting @c dismissAutomatically to false so
     * as to update the prompt while it is being displayed.
     * @param newValidationMessage The validation message of the prompt.
     *
     * @since BlackBerry 10.0.0
     */
    void setValidationMessage(const QString& newValidationMessage);

    /*!
     * @brief Sets whether the text can be displayed as emoticons.
     * @param newEmoticonsEnabled Whether the prompt supports emoticons.
     *
     * @since BlackBerry 10.0.0
     */
    void setEmoticonsEnabled(bool newEmoticonsEnabled);

    /*!
     * @brief Sets the preference for displaying a password toggle switch.
     * @param value The preference for including the password toggle switch in the dialog box.
     *
     * @since BlackBerry 10.0.0
     */
    void setIncludeShowPassword(bool value);

    /*!
     * @brief Sets the flag indicating if a toggle switch for remembering the credentials should be included in the prompt.
     * @param value @c true if a toggle for remembering the credentials should be included, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    void setIncludeRememberMe(bool value);

    /*!
     * @brief Sets the @c autoUpdateEnabled flag of the dialog.
     * @param update @c true if the dialog will update automatically,
     * @c false if the dialog will not update automatically (in which case the @c show() method
     * must be called after updating the dialog presentation properties).
     *
     * @since BlackBerry 10.2.0
     */
    void setAutoUpdateEnabled(bool update);

    /*!
     * @brief Sets whether the toggle switch for @c includeRememberMe will be selected by default.
     * @param newRememberMeSelected @c true if the toggle should be selected by default, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    void setRememberMeChecked(bool newRememberMeSelected);

    /*!
     * @brief Sets the text associated with the toggle switch for @c includeRememberMe.
     * @param newRememberMeText The new text for the toggle for @c includeRememberMe.
     *
     * @since BlackBerry 10.0.0
     */
    void setRememberMeText(const QString& newRememberMeText);

    /*!
     * @brief Sets the prompt's default button.
     * @details @c newDefaultButton must be one of the buttons managed by this instance, or @c NULL.
     * If @c NULL is specified, then no button will be associated with the return key action.
     *
     * If a non-managed button is specified, then this property is undefined.
     * @param newDefaultButton The button to associate with the return key action.
     *
     * @since BlackBerry 10.0.0
     */
    void setDefaultButton(bb::system::SystemUiButton* newDefaultButton);

    /*!
     * @brief The maximum number of buttons that can be shown without causing an overflow.
     * @details Values outside the range [1,3] will reset the property to its default value, -1.
     * If @c newButtonAreaLimit is smaller than the number of buttons that will be displayed, all buttons will be stacked vertically.
     * @param newButtonAreaLimit The maximum number of buttons in the button area.
     *
     * @since BlackBerry 10.0.0
     */
    void setButtonAreaLimit(int newButtonAreaLimit);

    /*!
     * @brief Sets whether the prompt is dismissed when a button is selected.
     * @param automaticDismissal @c true if the prompt should be automatically dismissed on a button press,
     * @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    void setDismissAutomatically(bool automaticDismissal);

    /*!
     * @brief Sets whether an activity indicator is displayed on the title bar of the dialog.
     * @param visible @c true if the dialog will display an activity indicator, @c false otherwise.
     *
     * @since BlackBerry 10.2.0
     */
    void setActivityIndicatorVisible(bool visible);

    /*!
     * @brief Sets the return key action for the prompt.
     * @param newReturnKeyAction The new return key action.
     *
     * @since BlackBerry 10.0.0
     */
    void setReturnKeyAction(bb::system::SystemUiReturnKeyAction::Type newReturnKeyAction);

    /*!
     * @brief Sets the modality for the prompt.
     * @param newModality The new modality preference.  See @c bb::system::SystemUiModality for the list of possible values.
     *
     * @since BlackBerry 10.0.0
     */
    void setModality(bb::system::SystemUiModality::Type newModality);

    /*!
     * @brief Resets the title of the prompt to @c QString::null.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetTitle();

    /*!
     * @brief Resets the main text of the prompt to @c QString::null.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetBody();

    /*!
     * @brief Resets the validation message of the prompt to @c QString::null.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetValidationMessage();

    /*!
     * @brief Resets whether the text can display emoticons to @c false.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetEmoticonsEnabled();

    /*!
     * @brief Resets the username input field for this prompt.
     * @details All properties of the username input field will be reset.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetUsernameField();

    /*!
     * @brief Resets the password input field for this prompt.
     * @details All properties of the password input field will be reset.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetPasswordField();

    /*!
     * @brief Resets the flag to show the toggle for showing the entered password to @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetIncludeShowPassword();

    /*!
     * @brief Resets the flag to show the toggle for remembering the credentials to @c true.
     * @details To reset the selection state for the toggle, use @c resetRememberMeChecked().
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetIncludeRememberMe();

    /*!
     * @brief Resets the @c autoUpdateEnabled flag to @c false.
     *
     * @since BlackBerry 10.2.0
     */
    Q_INVOKABLE void resetAutoUpdateEnabled();

    /*!
     * @brief Resets the selection state for the toggle switch for @c includeRememberMe to true.
     * @details To reset whether to include the toggle switch use @c resetIncludeRememberMe().
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetRememberMeChecked();

    /*!
     * @brief Resets the text for the toggle switch for @c includeRememberMe to @c "Remember Me".
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetRememberMeText();

    /*!
     * @brief Resets the confirmation button for this prompt.
     * @details The label of the button will be reset to its default value of @c "Login".
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetConfirmButton();

    /*!
     * @brief Resets the custom action button for this prompt.
     * @details When the button resets, its label will be a default-constructed @c QString so this button will be omitted when making @c show() and @c exec() requests.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetCustomButton();

    /*!
     * @brief Resets the cancellation button for this prompt.
     * @details The label of the cancellation button will be reset to its default value of @c "Cancel".
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetCancelButton();

    /*!
     * @brief Resets the default button for this prompt to @c confirmButton.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetDefaultButton();

    /*!
     * @brief Resets the maximum number of buttons to accommodate in the prompt button area without overflow to -1.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetButtonAreaLimit();

    /*!
     * @brief Resets whether the prompt is dismissed when a button is selected to @c true.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetDismissAutomatically();

    /*!
     * @brief Resets the dialog's @c activityIndicatorVisible property to its default value.
     *
     * @since BlackBerry 10.2.0
     */
    Q_INVOKABLE Q_REVISION(1) void resetActivityIndicatorVisible();

    /*!
     * @brief Resets the return key action of the prompt to @c bb::system::SystemUiReturnKeyAction::Default.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetReturnKeyAction();

    /*!
     * @brief Resets the modality of the prompt to @c bb::system::SystemUiModality::Application.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE void resetModality();

    /*!
     * @brief Retrieves the result of the last completed request.
     *
     * @details If no request has been made, or if a request is pending, @c bb::system::SystemUiResult::None is returned.
     * @return The result of the last completed request.  See @c bb::system::SystemUiResult for the list of possible results.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiResult::Type result() const;

    /*!
     * @brief Retrieves the error that occurred during the request.
     *
     * @details The return value will be reset when a new request is made.
     * @return The error that occurred.  See @c bb::system::SystemUiError for the list of possible errors.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiError::Type error() const;

    /*!
     * @brief Returns the button selected when a button selection is made.
     * @details If no button was selected, 0 will be returned.
     *
     * This function will return the result of the button selection of @c show() and @c exec().
     *
     * The return value will be reset when a new request is made.
     *
     * This instance retains ownership of the returned value.
     * @return The button selected by the user.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE bb::system::SystemUiButton* buttonSelection() const;

    /*!
     * @brief Returns the value in the username input field if the confirmation button was selected.
     *
     * The return value will be reset when a new request is made.
     *
     * @return The value in the username input field entered by the user.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE QString usernameEntry() const;

    /*!
     * @brief Returns the value in the password input field if the confirmation button was selected.
     *
     * The return value will be reset when a new request is made.
     *
     * @return The value in the password input field entered by the user.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE QString passwordEntry() const;

    /*!
     * @brief Returns the state of the toggle for remembering the entered credentials if the confirmation button
     * was selected.
     * @details If the confirmation button was not selected or the toggle was not displayed in the prompt, @c false will be returned.
     *
     * The return value will be reset when a new request is made.
     *
     * @return @c true if the toggle for remembering the entered credentials was checked, @c false otherwise.
     *
     * @since BlackBerry 10.0.0
     */
    Q_INVOKABLE bool rememberMeSelection() const;

public Q_SLOTS:
    /*!
     * @brief Displays a prompt based on current property values.
     * @details The result of the request can be retrieved with the @c SystemCredentialsPrompt::result property, or using the @c finished() signal.
     * The button selection can be retrieved with the @c SystemCredentialsPrompt::buttonSelection property.
     * The values in the username and password input fields can be retrieved using the @c usernameEntry() and @c passwordEntry() methods respectively.
     * The state of the toggle for remembering the entered credentials can be retrieved using the @c rememberMeSelection() method.
     *
     * Control is returned to the caller immediately. For a blocking request, use @c exec().
     *
     * @since BlackBerry 10.0.0
     */
    void show();

    /*!
     * @brief Displays the prompt based on current property values.
     * @details The result of the request can be retrieved with the @c SystemCredentialsPrompt::result property, or using the @c finished() signal.
     * The button selection can be retrieved with the @c SystemCredentialsPrompt::buttonSelection property.
     * The values in the username and password input fields can be retrieved using the @c usernameEntry() and @c passwordEntry() methods respectively.
     * The state of the toggle for remembering the entered credentials can be retrieved using the @c rememberMeSelection() method.
     *
     * Unlike @c show(), this function will block until a button selection is made. If the dialog is already on the screen,
     * this method will return immediately with @c bb::system::SystemUiResult::DialogCannotBlock.
     *
     * @note Blocking occurs by starting a nested @c QEventLoop. To use this method safely, the following conditions must be met:
     * - Any connections to this slot must use a @c Qt::QueuedConnection, or the slot must be triggered using @c QTimer::singleShot(), and
     * - @c QObject::deleteLater() must be used in place of @c delete when deleting the dialog box object.
     * If these conditions are not met, unexpected behavior may result.
     *
     * @return The result of the request.  See @c bb::system::SystemUiresult for the list of possible results.
     *
     * @since BlackBerry 10.0.0
     */
    bb::system::SystemUiResult::Type exec();

    /*!
     * @brief Updates an on-screen prompt dialog based on the current property values.
     * @details If the dialog is not on screen, this method returns immediately and no changes
     * are made to the dialog.
     *
     * @since BlackBerry 10.2.0
     */
    Q_REVISION(1) void update();

    /*!
     * @brief Cancels the prompt if it is displayed.
     *
     * @since BlackBerry 10.0.0
     */
    void cancel();

Q_SIGNALS:

    /*!
     * @brief Emitted when a request is completed.
     *
     * @details The button selection can be retrieved with @c buttonSelection().
     * The values in the username and password input fields can be retrieved using @c usernameEntry() and @c passwordEntry() respectively.
     * The state of the toggle for remembering the entered credentials can be retrieved using @c rememberMeSelection().
     * @param value The result of the request.  See @c bb::system::SystemUiResult for the list of possible results.
     *
     * @since BlackBerry 10.0.0
     */
    void finished(bb::system::SystemUiResult::Type value);

    /*!
     * @brief Emitted when the @c title property is changed programmatically.
     * @param value The new value of the @c title property.
     *
     * @since BlackBerry 10.0.0
     */
    void titleChanged(const QString& value);

    /*!
     * @brief Emitted when the @c body property is changed programmatically.
     * @param value The new value of the @c body property.
     *
     * @since BlackBerry 10.0.0
     */
    void bodyChanged(const QString& value);

    /*!
     * @brief Emitted when the @c validationMessage property is changed programmatically.
     * @param newValidationMessage The new value of the @c validationMessage property.
     *
     * @since BlackBerry 10.0.0
     */
    void validationMessageChanged(const QString& newValidationMessage);

    /*!
     * @brief Emitted when the @c emoticonsEnabled property is changed programmatically.
     * @param newEmoticonsEnabled The new value of the @c emoticonsEnabled property.
     *
     * @since BlackBerry 10.0.0
     */
    void emoticonsEnabledChanged(bool newEmoticonsEnabled);

    /*!
     * @brief Emitted when the @c includeShowPassword property is changed programmatically.
     * @param value The new value of the @c includeShowPassword property.
     *
     * @since BlackBerry 10.0.0
     */
    void includeShowPasswordChanged(bool value);

    /*!
     * @brief Emitted when the @c includeRememberMe property is changed programmatically.
     * @param value The new value of the @c includeRememberMe property.
     *
     * @since BlackBerry 10.0.0
     */
    void includeRememberMeChanged(bool value);

    /*!
     * @brief Emitted when the @c autoUpdateEnabled property is changed programmatically.
     * @param value The new value of the @c autoUpdateEnabled property.
     *
     * @since BlackBerry 10.2.0
     */
    void autoUpdateEnabledChanged(bool value);

    /*!
     * @brief Emitted when the @c rememberMeChecked property is changed programmatically.
     * @details When the user dismisses the dialog box, the user selection is available using @c rememberMeSelection().
     * @param newRememberMeSelected The new value of the @c rememberMeChecked property.
     *
     * @since BlackBerry 10.0.0
     */
    void rememberMeCheckedChanged(bool newRememberMeSelected);

    /*!
     * @brief Emitted when the @c rememberMeText property is changed programmatically.
     * @param newRememberMeText The new value of the @c rememberMeText property.
     *
     * @since BlackBerry 10.0.0
     */
    void rememberMeTextChanged(const QString& newRememberMeText);

    /*!
     * @brief Emitted when the @c defaultButton property is changed programmatically.
     * @param newDefaultButton The new value of the @c defaultButton property, or @c NULL if none is set.
     *
     * @since BlackBerry 10.0.0
     */
    void defaultButtonChanged(bb::system::SystemUiButton* newDefaultButton);

    /*!
     * @brief Emitted when the @c buttonAreaLimit property is changed programmatically.
     * @param newButtonAreaLimit The new value of the @c buttonAreaLimit property.
     *
     * @since BlackBerry 10.0.0
     */
    void buttonAreaLimitChanged(int newButtonAreaLimit);

    /*!
     * @brief Emitted when the @c dismissAutomatically property is changed programmatically.
     * @param automaticDismissal The new value of the @c dismissAutomatically property.
     *
     * @since BlackBerry 10.0.0
     */
    void dismissAutomaticallyChanged(bool automaticDismissal);

    /*!
     * @brief Emitted when the @c activityIndicatorVisible property is changed programmatically.
     * @param value The new value of the @c activityIndicatorVisible property.
     *
     * @since BlackBerry 10.2.0
     */
    Q_REVISION(1) void activityIndicatorVisibleChanged(bool value);

    /*!
     * @brief Emitted when the @c returnKeyAction property is changed programmatically.
     * @param newReturnKeyAction The new value of the @c returnKeyAction property.
     *
     * @since BlackBerry 10.0.0
     */
    void returnKeyActionChanged(bb::system::SystemUiReturnKeyAction::Type newReturnKeyAction);

    /*!
     * @brief Emitted when the @c modality property is changed programmatically.
     * @param newModality The new value of the @c modality property.
     *
     * @since BlackBerry 10.0.0
     */
    void modalityChanged(bb::system::SystemUiModality::Type newModality);

//!@cond PRIVATE
    /*!
     * @xmlonly
     * <qml>
     * <param name="value" type="bb::system::SystemUiResult::Type"/>
     * </qml>
     * @endxmlonly
     */
    void finished( int value );
    /*!
     * @xmlonly
     * <qml>
     * <param name="newReturnKeyAction" type="bb::system::SystemUiReturnKeyAction::Type"/>
     * </qml>
     * @endxmlonly
     */
    void returnKeyActionChanged(int newReturnKeyAction);
    /*!
     * @xmlonly
     * <qml>
     * <param name="newModality" type="bb::system::SystemUiModality::Type"/>
     * </qml>
     * @endxmlonly
     */
    void modalityChanged(int newModality);
//!@endcond

private:
//!@cond PRIVATE
    Q_DECLARE_PRIVATE(SystemCredentialsPrompt)
    Q_DISABLE_COPY(SystemCredentialsPrompt)
    QScopedPointer<SystemCredentialsPromptPrivate> d_ptr;
//!@endcond
};

} // namespace system
} // namespace bb

QML_DECLARE_TYPE(bb::system::SystemCredentialsPrompt)
#endif //  BB_SYSTEM_SYSTEMCREDENTIALSPROMPT_HPP
