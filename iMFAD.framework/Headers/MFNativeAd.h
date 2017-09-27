//
//  MFNativeAd.h
//  iMFAD
//
//  Created by 郭堯彰 on 2017/8/18.
//  Copyright © 2017年 clickforce. All rights reserved.
//

#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN
@class MFNativeAd;
@class MFAdImage;
@protocol MFNativeDelegate <NSObject>

@optional

//All No Ad
- (void)requestAdFail;

/**
 ClickForce Native Ad
 */

- (void)onMFNativeAdDidLoad:(MFNativeAd *)nativeAd;

- (void)onMFNativeAdClick:(MFNativeAd *)nativeAd;

/**
 Facebook Native Ad
 */

- (void)onFBNativeAdDidLoad:(MFNativeAd *)nativeAd;

- (void)onFBNativeAdDidClick;

- (void)onFBNativeAdWillLogImpression;

- (void)onFBNativeADFailWithError:(NSError *)error;


@end

@interface MFNativeAd : NSObject

@property (nonatomic, copy) NSString * _Nullable bannerId;


/**
 ClickForce Native Ad
 */
@property (nonatomic, copy, readonly, nullable) NSString *title;

@property (nonatomic, copy, readonly, nullable) NSString *content;

@property (nonatomic, copy, readonly, nullable) NSString *advertiser;

@property (nonatomic, copy, readonly, nullable) NSString *buttonTitle;

@property (nonatomic, strong, readonly, nullable) MFAdImage *coverImg;

@property (nonatomic, weak, nullable) id <MFNativeDelegate>delegate;

/**
 Facebook Native Ad
 */
@property (nonatomic, copy, readonly, nullable) NSString *fb_Title;

@property (nonatomic, copy, readonly, nullable) NSString *fb_Subtitle;

@property (nonatomic, copy, readonly, nullable) NSString *fb_SocialContext;

@property (nonatomic, copy, readonly, nullable) NSString *fb_CallToAction;

@property (nonatomic, strong, readonly, nullable) NSURL *fb_IconURL;

@property (nonatomic, strong, readonly, nullable) NSURL *fb_CoverImageURL;

@property (nonatomic, copy, readonly, nullable) NSString *fb_RawBody;

@property (nonatomic, copy, readonly, nullable) NSString *fb_body;

@property (nonatomic, strong, readonly, nullable) NSURL *fb_AdChoicesIconURL;

@property (nonatomic, copy, readonly, nullable) NSURL *fb_AdChoicesLinkURL;

@property (nonatomic, copy, readonly, nullable) NSString *fb_AdChoicesText;

@property (nonatomic, copy, readonly, nonnull) NSString *fb_PlacementID;

#pragma mark 開始取得廣告
- (void)requestAd;

#pragma mark 設定是否輸出除錯訊息
- (void)debugInfo:(BOOL)state;

#pragma mark 取得 FB原生物件
- (NSObject *)getFBNativeObj;

#pragma mark 回傳SDK版本
+ (NSString *)version;

#pragma mark The whole area of the UIView will be clickable.
- (void)registerViewForInteraction:(UIView *_Nullable)view
                withViewController:(nullable UIViewController *)viewController;

- (void)setFBAdClick:(UIView *)fbAdView controller:(UIViewController *)fbAdViewController;

@end



@interface MFAdImage : NSObject

@property (nonatomic, copy, readonly, nonnull) NSURL *url;

@property (nonatomic, assign, readonly) NSInteger width;

@property (nonatomic, assign, readonly) NSInteger height;


/**
 This is a method to initialize an MFAdImage.
 
 - Parameter url: the image url.
 - Parameter width: the image width.
 - Parameter height: the image height.
 */
- (instancetype _Nullable )initWithURL:(NSURL *)url
                      width:(NSInteger)width
                     height:(NSInteger)height NS_DESIGNATED_INITIALIZER;

/**
 Loads an image from self.url over the network, or returns the cached image immediately.
 
 - Parameter block: Block to handle the loaded image.
 */
- (void)loadImageAsyncWithBlock:(nullable void (^)(UIImage * __nullable image))block;

@end
NS_ASSUME_NONNULL_END

