//
//  Created by ideawu on 15-1-18.
//  Copyright (c) 2015年 ideawu. All rights reserved.
//
#ifndef IKit_IPullRefresh_h
#define IKit_IPullRefresh_h

#import <UIKit/UIKit.h>
#import "IView.h"

@protocol IPullRefreshDelegate;

@interface IPullRefresh : NSObject <UIScrollViewDelegate>

@property (nonatomic) id delegate;
@property (nonatomic) IView *headerView;
@property (nonatomic) IView *footerView;

/**
 * The visible portion of headerView to trigger a IRefreshBegin event, default is 1.0
 */
@property (nonatomic) CGFloat headerVisibleRateToRefresh;
/**
 * The visible portion of footerView to trigger a IRefreshBegin event, default is 1.0
 */
@property (nonatomic) CGFloat footerVisibleRateToRefresh;

- (id)initWithScrollView:(UIScrollView *)scrollView;

// these are the methods that a UIScrollViewDelegate should call
- (void)scrollViewDidEndDragging:(UIScrollView *)scrollView willDecelerate:(BOOL)decelerate;
- (void)scrollViewDidScroll:(UIScrollView*)scrollView;

- (void)endRefresh:(IView *)view;
- (void)beginHeaderRefresh;
- (void)beginFooterRefresh;

@end


@protocol IPullRefreshDelegate <NSObject>

//@optional
- (void)onRefresh:(IView *)view state:(IRefreshState)state;

@end


#endif
