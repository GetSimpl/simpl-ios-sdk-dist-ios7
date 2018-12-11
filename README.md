# simpl-ios-sdk-dist-ios7

[![Version](https://img.shields.io/cocoapods/v/GetSimpl-iOS.svg)](http://cocoapods.org/pods/GetSimpl-iOS)
[![Platform](https://img.shields.io/badge/platform-iOS-lightgrey.svg)]()

## How to install

### CocoaPods :
[CocoaPods](https://cocoapods.org/) is a dependency manager for Cocoa projects. You can install it with the following command:
````
$ gem install cocoapods
````
To integrate GetSimpl into your Xcode project using CocoaPods, specify it in your Podfile:

````
pod 'GetSimpl-iOS'
````

Then, run the following command:
````
$ pod install
````

## iOS Integration

* Target -> Build Settings -> ENABLE_BITCODE -> Mark it as NO.

* Add the following to your Info.plist file:

````
<key>CFBundleURLTypes</key>
<array>
  <dict>
    <key>CFBundleURLSchemes</key>
    <array>
      <string>smpYourMerchantID</string>
    </array>
  </dict>
</array>
````

Note that you must add your merchantID in `smpYourMerchantID` such as `smp55d72761ec60ytbnk97414182`.

* For iOS 9+ also add the following to your Info.plist file :

````
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSExceptionDomains</key>
    <dict>
      <key>getsimpl.com</key>
      <dict>
        <key>NSExceptionAllowsInsecureHTTPLoads</key>
        <true/>
        <key>NSIncludesSubdomains</key>
        <true/>
        <key>NSThirdPartyExceptionRequiresForwardSecrecy</key>
        <false/>
      </dict>
    </dict>  
</dict>
<key>LSApplicationQueriesSchemes</key>
<array>
    <string>simplApp</string>
</array>
````

* Developers can toggle between sandbox or production environment like below :
````
[GSManager enableSandBoxEnvironment:YES]
````

## How to use

* Import the Library :
````
#import "GetSimpl-iOS/GetSimpl.h" 
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

* To show Simpl option, merchants can use their own custom button. However they should use ```` buttonText ```` value from approval call above to display the text on the button.

* On clicking Simpl button, call the following method to start the transaction. This will open an OTP view for the user to enter . In the completion block transaction_token will be returned.
````
   GSUser *user = [[GSUser alloc] initWithPhoneNumber:@"user mobile number" email:@"user email"];
   // OrderId refers to the merchant generated order id of the transaction in progress
   NSDictionary *additionalParams = @{@"order_id": @"merchant order id"};
   [user setHeaderParams:additionalParams];
   
   GSTransaction *transaction = [[GSTransaction alloc] initWithUser:user amountInPaise:500];   
[ [GSManager sharedManager]  authorizeTransaction:transaction onCompletion:^(NSDictionary * jsonResponse, NSError *  error) {
  }];
````
Phone number of GSUser must be set before making authorizeTransaction call.
Once you have the transaction_token, pass it over to your server which in turn can pass the transaction details to Simpl.
