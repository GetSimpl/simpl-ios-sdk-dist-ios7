//
//  GSCallBackHandler.h
//  GetSimpl
//
//  Created by Alok Jha on 15/02/16.
//  Copyright © 2016 Simpl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSCallBackHandler : NSObject

/// Shared instance for GSCallBackHandler. Use this instance to make all subsequent calls.
+ (GSCallBackHandler * __nonnull)sharedInstance;

/// Checks whether GetSimpl framework can process the given url
///
/// \param url A NSURL object to check
- (BOOL)canHandleURL:(NSURL * __nonnull)url;

/// Method to process the incoming URL query and returns if succesful or not
///
/// \param application Singleton UIApplication object
///
/// \param url The URL resource to open
///
/// \param sourceApplication The bundle ID of the app that is requesting to open the URL (url)
///
/// \param annotation A property list object supplied by the caller to communicate information back to it.
- (BOOL)application:(UIApplication * __nonnull)application openURL:(NSURL * __nonnull)openURL sourceApplication:(NSString * __nullable)sourceApplication annotation:(id __nullable)annotation;


@end
