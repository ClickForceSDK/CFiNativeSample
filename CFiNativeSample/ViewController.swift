//
//  ViewController.swift
//  CFiNativeSample
//
//  Created by 郭堯彰 on 2017/9/1.
//  Copyright © 2017年 clickforce. All rights reserved.
//

import UIKit
import iMFAD

class ViewController: UIViewController {
    
    
    @IBOutlet var adView: UIView!
    @IBOutlet var coverImage: UIImageView!
    @IBOutlet var adTitle: UILabel!
    @IBOutlet var adBody: UILabel!
    @IBOutlet var advertiser: UILabel!
    @IBOutlet var adButtonText: UIButton!

    
    private var native :MFNativeAd?
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.native = MFNativeAd();
        self.native?.bannerId = "7619";
        self.native?.delegate = self;
        self.native?.mediaViewFram = CGRect(x: 28, y: 333, width: 320, height: 160);
        self.native?.adChoicesViewFram = CGRect(x: 310, y: 0, width: 20, height: 20);
        self.native?.request();
        let color = UIColor.black;
        self.adView.layer.borderColor = color.cgColor;
        self.adView.layer.borderWidth = 1.0;
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

}

extension ViewController:MFNativeDelegate{
    
    func onMFNativeAdDidLoad(_ nativeAd: MFNativeAd) {

        nativeAd.registerView(forInteraction: self.adView, with: self);
        self.adTitle.text = nativeAd.title;
        self.adBody.text = nativeAd.content;
        self.adButtonText.setTitle(nativeAd.buttonTitle, for: .normal);
        self.advertiser.text = nativeAd.advertiser;
        nativeAd.coverImg?.loadAsync(block: { image in
            self.coverImage.image = image;
        })
    }
    
    func onFBNativeAdDidLoad(_ nativeAd: MFNativeAd) {

        self.adTitle.text = nativeAd.fb_Title;
        self.adBody.text = nativeAd.fb_body;
        self.advertiser.text = "Sponsored";
        self.adButtonText.setTitle(nativeAd.fb_CallToAction, for: .normal);

        let data = try? Data(contentsOf: nativeAd.fb_CoverImageURL!)
        
        if let imageData = data {
            let image = UIImage(data: data!)
            self.coverImage.image = image;
        }

        self.view.addSubview(nativeAd.fb_MediaView!);
        self.adView.addSubview(nativeAd.fb_AdChoicesView!);
        nativeAd.setFBAdClick(self.adView, controller: self);
    }
    
    func onFBNativeADFailWithError() {
        
   
        
        print("Native ad failed to load with error: %@");
    }
    
    func requestAdFail() {
        print("No Ad");
    }
}

