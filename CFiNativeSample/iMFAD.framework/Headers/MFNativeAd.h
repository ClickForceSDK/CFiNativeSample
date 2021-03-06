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

- (void)onFBNativeADFailWithError;



@end

@interface MFNativeAd : NSObject

@property (nonatomic, copy) NSString * _Nullable bannerId;
@property CGRect mediaViewFram;
@property CGRect iconViewFram;
@property CGRect adChoicesViewFram;

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

@property (nonatomic, copy, readonly, nullable) NSString *fb_linkDescription;

@property (nonatomic, copy, readonly, nullable) NSString *fb_advertiserName;

@property (nonatomic, copy, readonly, nullable) NSString *fb_SocialContext;

@property (nonatomic, copy, readonly, nullable) NSString *fb_CallToAction;

@property (nonatomic, strong, readonly, nullable) NSURL *fb_IconURL;

@property (nonatomic, copy, readonly, nullable) NSString *fb_RawBody;

@property (nonatomic, copy, readonly, nullable) NSString *fb_body;

@property (nonatomic, copy, readonly, nullable) NSString *fb_sponsoredTranslation;

@property (nonatomic, copy, readonly, nonnull) NSString *fb_PlacementID;

@property  (nonatomic,strong,readonly, nullable) UIView *fb_MediaView;

@property (nonatomic,strong,readonly ,nullable) UIView *fb_IconView;

@property (nonatomic,strong,readonly,nullable) UIView *fb_AdChoicesView;

#pragma mark 開始取得廣告
- (void)requestAd;

#pragma mark 設定是否輸出除錯訊息
- (void)debugInfo:(BOOL)state;

#pragma mark 回傳SDK版本
+ (NSString *)version;

+ (NSString *)fbSDKVersion;

#pragma mark The whole area of the UIView will be clickable.
- (void)registerElementsView:(UIView *)elementsView clickView:(NSArray<UIView *> *)view controllervw:(UIViewController *)viewController;

- (void)setFBElements:(UIView *)fbAdView mediaView:(UIView *)fbmedia iconView:(UIView *)fbicon controller:(UIViewController *)fbAdViewController clickableViews:(NSArray<UIView *> *)cViews;

- (void)setFBElements:(UIView *)fbAdView iconView:(UIView *)fbicon controller:(UIViewController *)fbAdViewController clickableViews:(NSArray<UIView *> *)cViews;

- (void)unregisterView;

- (void)setScrollviewName:(UIView *)uscro;

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

