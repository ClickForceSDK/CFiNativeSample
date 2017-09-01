//
//  MFInterstitialView.h
//  iMFAD
//
//  Created by 郭堯彰 on 2017/8/3.
//  Copyright © 2017年 clickforce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

@protocol MFInterstitialViewDelegate <NSObject>

@optional
//回傳廣告查詢狀態
- (void)onRequestItstAdFail;

- (void)onRequestItstAdSuccess;

- (void)onClickItst;

- (void)onCloseItst;

@end


@interface MFInterstitialView : UIView
@property(nonatomic, strong) AVPlayer *contentPlayer;
@property (nonatomic, copy) NSString *bannerId;
@property(nonatomic, assign)UIViewController *rootViewController;
@property(nonatomic, assign)id<MFInterstitialViewDelegate>delegate;

#pragma mark 開始取得全版廣告
- (void)requestFullScreenAD;

#pragma mark 顯示取得廣告
- (void)show;

#pragma mark 設定是否輸出除錯訊息
- (void)debugInfo:(BOOL)state;


@end
