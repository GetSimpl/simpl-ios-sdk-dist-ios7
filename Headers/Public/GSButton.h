//
//  GSButton.h
//  GetSimpl
//
//  Created by Alok Jha on 15/02/16.
//  Copyright © 2016 Simpl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface GSButton : UIControl

/// Button background color. Defaults to Simpl branding color(R0 G209 B193 A1)
@property (nonatomic, strong) UIColor * __nonnull buttonColor;

/// Button border color. Defaults to Black Color with 10% alpha
@property (nonatomic, strong) UIColor * __nonnull buttonBorderColor;

/// Title text of button. Defaults to "Buy Now, Pay Later"
@property (nonatomic, copy) NSString * __nonnull titleText;

/// Title Color of Button. Defaults to White color
@property (nonatomic, strong) UIColor * __nonnull titleColor;

/// Font of button
@property (nonatomic, strong) UIFont * __nonnull titleFont;

/// Text color of "Powered by Simpl" text. Defaults to R94 G107 B125 A1
@property (nonatomic, strong) UIColor * __nonnull poweredByTextColor;

/// Separator line color. Defaults to Black Color with 8% alpha
@property (nonatomic, strong) UIColor * __nonnull separatorColor;


@end
