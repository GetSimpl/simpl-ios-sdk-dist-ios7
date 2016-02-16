# simpl-ios-sdk-dist-ios7

[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)]()

## How to install
### Manually :
Go to Repository release section and download the GetSimpl.framework.zip file from the latest release and unarchive it to get the latest framework file.


### CocoaPods :
[CocoaPods](https://cocoapods.org/) is a dependency manager for Cocoa projects. You can install it with the following command:
````
$ gem install cocoapods
````
To integrate GetSimpl into your Xcode project using CocoaPods, specify it in your Podfile:
````
use_frameworks!
pod 'GetSimpl'
````
Then, run the following command:
````
$ pod install
````

## iOS Integration
* Once you have received the SDK, add the GetSimpl framework into your Xcode Project. Make sure to checkmark "Copy items if needed" when Xcode shows the options for adding files.
* Target -> General -> Embedded Frameworks -> Click on "+" icon to add GetSimpl framework.
* Add the following to your Info.plist file:
````
    <key>CFBundleURLTypes</key>
    <array>
     <dict>
        <key>CFBundleURLSchemes</key>
        <array>
        // smp + YourMerchantID, like; smp55d72761ec60ytbnk97414182
        <string>smpYourMerchantID</string>
       </array>
     </dict>
    </array>
````
* For iOS 9 also add the following to your Info.plist file :
````
    <key>NSAppTransportSecurity</key>
    <dict>
      <key>NSAllowsArbitraryLoads</key>
      <true/>
    </dict>
    <key>LSApplicationQueriesSchemes</key>
     <array>
      <string>simplApp</string>
     </array>
````

* In you AppDelegate add the following lines: 
````
- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication     annotation: (id)annotation
    { if ([[GSCallBackHandler sharedInstance] canHandleURL:url]) {
      return [[GSCallBackHandler sharedInstance] application:application openURL:url sourceApplication:sourceApplication      annotation:annotation] ;
    }

  return YES;
   }
````

* Developers can toggle between sandbox or production environment like below :
````
[GSManager enableSandBoxEnvironment:YES]
````

## How to use

* Import the Library :
````
#import "GetSimpl/GetSimpl.h"
````

* Initialise the SDK with your merchantID, typically in your applications didFinishLaunchingOptions method:
````
[GSManager initializeWithMerchantID@:@"Your merchant id"];
````
* Check if user is pre-approved:
````
GSUser *user = [[GSUser alloc] initWithPhoneNumber:@"user mobile number" email:@"user email"];
[[GSManager sharedManager] checkApprovalForUser:user onCompletion:^(BOOL approved, BOOL isFirstTransactionOfUser,  NSString *buttonText ,NSError *error) {
 }]
````
      Bool approved : If GSUser is pre-approved or not
      Bool isFirstTransactionOfUser : If user has already done transactions previously or not
      String/NSString buttonText : The text to display on Simpl button. If GSUser is pre-approved,this will contain a value specific to merchant with default value of "Buy Now, Pay Later". Will be nil if GSUser is not pre-approved.
      NSError error : Error if any
 
If the user is approved and merchant should show Simpl button and if the user is not an approved user,do not show the   Simpl button.

* Realtime approval :
For some merchants who prefer to not share data upfront but willing to approve users in realtime by sharing data before transaction may use the approval call like below :
````
GSUser *user = [[GSUser alloc] initWithHashedPhoneNumber:@"hashed value of user phone number"];
user.extraParams = @{@"wallet_balance_in_paise" : @30000,@"transaction_amount_in_paise" : @20000};
[[GSManager sharedManager] checkApprovalForUser:user onCompletion:^(BOOL approved, BOOL isFirstTransactionOfUser,  NSString *buttonText ,NSError *error) {
 }]
````

```` 
extraParams ->  Extra properties of GSUser to be set as Key-Value pairs.Example of some keys are transaction_amount_in_paise, wallet_balance_in_paise,failed_transaction_bank_name,user_location,theatre_location,member_since, signed_in , etc.
This property has been provided so that merchants can provide additional parameters for real-time approval without upgrading the SDK.
````
If merchant is using hashedPhoneNumber to check for pre-approval then the above keys will be used for realtime approval of users provided merchant has realtime configuration enabled on server side. 

* For Simpl button , merchants can use GSButton class given by SDK which can be customized through following properties:
````

/// Button background color. Defaults to Simpl branding color
@property (nonatomic, strong) UIColor *buttonColor;

/// Button border color. Defaults to Black Color with 10% alpha
@property (nonatomic, strong) UIColor *buttonBorderColor;

/// Title text of button. Defaults to "Buy Now, Pay Later"
@property (nonatomic, copy) NSString *titleText;

/// Title Color of Button. Defaults to White color
@property (nonatomic, strong) UIColor *titleColor;

/// Font of button
@property (nonatomic, strong) UIFont *titleFont;

/// Text color of "Powered by Simpl" text. Defaults to R94 G107 B125 A1
@property (nonatomic, strong) UIColor *poweredByTextColor;

/// Separator line color. Defaults to Black Color with 8% alpha
@property (nonatomic, strong) UIColor *separatorColor;

````

* On clicking Simpl button, call the following method to start the transaction. This will open an OTP view for the user to enter . In the completion block transaction_token will be returned.
````
   GSUser *user = [[GSUser alloc] initWithPhoneNumber:@"user mobile number" email:@"user email"];
   GSTransaction *transaction = [[GSTransaction alloc] initWithUser:user amountInPaise:500];
[ [GSManager sharedManager]  authorizeTransaction:transaction onCompletion:^(NSDictionary * jsonResponse, NSError *  error) {
  }];
````
Phone number of GSUser must be set before making authorizeTransaction call.
Once you have the transaction_token, pass it over to your server which in turn can pass the transaction details to Simpl.
