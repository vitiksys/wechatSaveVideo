//
//  CCAutoLikeHeader.h
//  WeChatTimeLineRobot
//
//  Created by Cocos on 16/4/5.
//  Copyright © 2016年 Cocos. All rights reserved.
//
@interface FIFOFileQueue : NSObject
-(BOOL)push:(id)push;
-(id)getAll;
@end

@interface WCCommentUploadMgr : NSObject
-(void)tryStartNextTask;
-(void)pushBackTopTask;
-(void)popTopTask;
-(void)addComment:(id)comment;
-(void)addCommentToWCObjectCache:(id)wcobjectCache;
@end
//WCContentItem:
@interface WCCommentItem : NSObject
@property(retain, nonatomic) NSString* clientID;
@property(assign, nonatomic) unsigned inQueueTime;
@property(assign, nonatomic) unsigned createTime;
@property(assign, nonatomic) int source;
@property(assign, nonatomic) int type;
@property(retain, nonatomic) NSString* itemID;
@property(retain, nonatomic) NSString* toUserName;
@end
@interface WCContentItem : NSObject
{
    NSString *title;
    NSString *desc;
    NSString *titlePattern;
    NSString *descPattern;
    NSString *linkUrl;
    NSString *linkUrl2;
    int type;
    int flag;
    NSString *username;
    NSString *nickname;
    int createtime;
    NSMutableArray *mediaList;
}
@property(nonatomic) int createtime; // @synthesize createtime;
@property(retain, nonatomic) NSString *desc; // @synthesize desc;
@property(retain, nonatomic) NSString *descPattern; // @synthesize descPattern;
@property(retain, nonatomic) NSString *linkUrl; // @synthesize linkUrl;
@property(retain, nonatomic) NSString *linkUrl2; // @synthesize linkUrl2;
@property(retain, nonatomic) NSMutableArray *mediaList; // @synthesize mediaList;
@property(retain, nonatomic) NSString *nickname; // @synthesize nickname;
@property(retain, nonatomic) NSString *title; // @synthesize title;
@property(retain, nonatomic) NSString *titlePattern; // @synthesize titlePattern;
@property(nonatomic) int type; // @synthesize type;
@property(retain, nonatomic) NSString *username; // @synthesize username;

@end
@interface WCAdvertiseInfo : NSObject
@end
//@class MMUIButton;
@interface WCDataItem : NSObject
@property(assign, nonatomic) BOOL likeFlag;
@property(retain, nonatomic) NSString* username;
@property(retain, nonatomic) NSString* tid;
@property(retain, nonatomic) WCAdvertiseInfo* advertiseInfo;
@property(retain, nonatomic) NSString *sourceUrl;
@property(retain, nonatomic) NSString *sourceUrl2;
@property(retain, nonatomic) NSString *contentDesc;
@property(retain, nonatomic) NSString *contentDescPattern;

@property(retain, nonatomic) WCContentItem *contentObj;
-(id)itemID;
@end

@interface WCLikeButton : NSObject
@property(retain, nonatomic) WCDataItem* m_item;
//点赞取消触发方法
-(void)LikeBtnReduceEnd;
//用于初始化
-(id)initWithDataItem:(id)dataItem;
@end


@interface SettingUtil : NSObject
+(id)getCurUsrName;
@end
/**
 *  wcurl
 */
@interface WCUrl : NSObject
@property(retain, nonatomic) NSString *md5; // @synthesize md5;
@property(nonatomic) int type; // @synthesize type;
@property(retain, nonatomic) NSString *url; // @synthesize url;
@end
/**
 *  WCMediaItem
 */

@interface WCMediaItem : NSObject
@property(retain, nonatomic) NSString *attachShareTitle; // @synthesize attachShareTitle;
@property(retain, nonatomic) WCUrl *attachThumbUrl; // @synthesize attachThumbUrl;
@property(retain, nonatomic) WCUrl *attachUrl; // @synthesize attachUrl;
@property(nonatomic) int attachVideoTotalTime; // @synthesize attachVideoTotalTime;
@property(nonatomic) int commentCount; // @synthesize commentCount;
@property(retain, nonatomic) NSMutableArray *commentUsers; // @synthesize commentUsers;
@property(nonatomic) int createTime; // @synthesize createTime;
@property(retain, nonatomic) WCUrl *dataUrl; // @synthesize dataUrl;
@property(retain, nonatomic) NSString *desc; // @synthesize desc;
@property(retain, nonatomic) NSString *descPattern; // @synthesize descPattern;
@property(nonatomic) struct CGSize imgSize; // @synthesize imgSize;

@property(nonatomic) int likeCount; // @synthesize likeCount;
@property(nonatomic) _Bool likeFlag; // @synthesize likeFlag;
@property(retain, nonatomic) NSMutableArray *likeUsers; // @synthesize likeUsers;
@property(retain, nonatomic) WCUrl *lowBandUrl; // @synthesize lowBandUrl;
@property(retain, nonatomic) NSString *mid; // @synthesize mid;
@property(retain, nonatomic) NSMutableArray *previewUrls; // @synthesize previewUrls;
@property(retain, nonatomic) NSString *source; // @synthesize source;
@property(nonatomic) int subType; // @synthesize subType;
@property(retain, nonatomic) NSString *title; // @synthesize title;
@property(retain, nonatomic) NSString *titlePattern; // @synthesize titlePattern;
@property(nonatomic) int type; // @synthesize type;
@property(retain, nonatomic) NSString *userData; // @synthesize userData;
@property(nonatomic) int withCount; // @synthesize withCount;
@property(retain, nonatomic) NSMutableArray *withUsers; // @synthesize withUsers;
@property(nonatomic) unsigned long long xorEncrpyKey; // @synthesize xorEncrpyKey;


@end

@interface MMServiceCenter : NSObject
+(id)defaultCenter;
-(id)getService:(Class)className;
@end

@interface WCFacade : NSObject
-(WCDataItem *)getTimelineDataItemOfIndex:(int)index;
//点赞内部调用,这里不用到
-(void)likeObject:(id)object ofUser:(id)user source:(int)source;
////点赞内部调用,这里不用到
-(BOOL)unLikeObject:(id)object ofUser:(id)user;
@end

@interface WCTimeLineViewController : NSObject
-(int)calcDataItemIndex:(int)index;
-(void)ccStartAutoLike;
-(void)ccUpdateDataItemsWithNumber:(int)number;
-(void)ccStartQueueToLike;
-(void)reloadTableView;
- (void)tableView:(UITableView *)tblView didSelectRowAtIndexPath:(NSIndexPath *)IndexPath;
@end


@interface WCSightView :UIControl
{
    _Bool m_bIsLongPressHandled;
    UIImageView *m_thumbImg;
    WCDataItem *m_dataItem;

    UIView *m_fullScreenContent;
    UIView *m_fullScreenTips;

    UIView *m_coverMask;
    int m_currMaskType;
    struct CGRect sightRectInTimeLine;

    _Bool m_fullScreenPlaying;
    _Bool m_waitFullScreenPlaying;
    _Bool m_isLoading;
    _Bool m_bfullScreenPlayAttachVideo;
    _Bool m_bHasAlreadyDownLoadVideo;
    _Bool m_bCachedRealDownloadProgress;
    _Bool m_bTimelineScene;
    int m_currentPage;
    struct CGSize m_initPlayerSize;
    _Bool m_bHasPlayedOnceForTips;
    _Bool m_closeForViewDetail;
    _Bool m_isImageReady;
    _Bool m_isSightReady;
    WCMediaItem *m_mediaData;

    NSString *m_SightPath;
    NSString *_m_cpKey;
}

- (void)LongPressEvents:(id)arg1;
- (void)OnWCTimeLineWillBePopedNotify:(id)arg1;
- (void)WCTimeLineWillAppearNotify:(id)arg1;
- (void)addObservers;
- (void)animationShow:(_Bool)arg1;
- (void)cacheFakeProgressValue;
- (struct CGSize)calNewSizeForSightPlayer:(double)arg1 videoHeight:(double)arg2 frameWidth:(double)arg3 frameHeight:(double)arg4;
- (double)calSightVideoMaxHeight;
- (double)calSightViedoCenterY;
- (double)calTransformScale:(double)arg1 videoHeight:(double)arg2 frameWidth:(double)arg3 frameHeight:(double)arg4;
- (void)clearAttachVideoResource;
- (void)clearShortVideo;
- (void)clickFullScreenWindow;
- (void)dealloc;
- (void)endViewStreamVideo;
- (void)endViewVideo;
- (void)exitFullScreenPlay;
- (id)getDetailButtonTitle;
- (id)getImage;
- (id)getRootView:(id)arg1;
- (void)hideCoverMaskWithAnim:(_Bool)arg1;
- (void)initCoverMask;
- (void)initData:(id)arg1;
- (void)initFullPlayWindow;
- (id)initWithMediaData:(id)arg1;
- (id)initWithMediaData:(id)arg1 withFrame:(struct CGRect)arg2;
- (_Bool)isAutoDownLoadVideo;
- (_Bool)isAutoPlayVideo;
- (_Bool)isFullScreenPlaying;
- (_Bool)isSightVideoExist;
- (void)layoutSubviews;
- (void)longPressFullScreenWindow:(id)arg1;
@property(retain, nonatomic) NSString *m_SightPath; // @synthesize m_SightPath;
@property(nonatomic) _Bool m_bTimelineScene; // @synthesize m_bTimelineScene;
@property(retain, nonatomic) NSString *m_cpKey; // @synthesize m_cpKey=_m_cpKey;
@property(retain, nonatomic) WCDataItem *m_dataItem; // @synthesize m_dataItem;

@property(readonly, nonatomic) _Bool m_isImageReady; // @synthesize m_isImageReady;
@property(readonly, nonatomic) _Bool m_isSightReady; // @synthesize m_isSightReady;
@property(readonly, nonatomic) WCMediaItem *m_mediaData; // @synthesize m_mediaData;
- (void)makeFakeProgress;
- (void)onBeginDownload:(id)arg1 downloadType:(int)arg2;
- (void)onCancelShareVideoToFriend;
- (void)onClick;
- (void)onClickDetailButton;
- (void)onClickFavVideoMenu;
- (void)onClickFullPlayView;
- (void)onClickFullPlayViewForViewAttachVideo;
- (void)onClickPlayAttachVideoBtn:(id)arg1;
- (void)onClickWCSight:(id)arg1;
- (void)onClosePlayer;
- (void)onClosePlayerForViewDetail:(id)arg1;
- (void)onDoubleClickWCSight:(id)arg1;
- (void)onDownloadFinish:(id)arg1 downloadType:(int)arg2;
- (void)onDownloadMediaProcessChange:(id)arg1 downloadType:(int)arg2 current:(long long)arg3 total:(long long)arg4;
- (void)onEndFullPlay;
- (void)onFullSightPlayEnd:(_Bool)arg1;
- (void)onItemCleared;
- (void)onLongPressFullPlayView;
- (void)onMainWindowFrameChanged;
- (void)onOrientationChanged;
- (void)onPausePlayer;
- (_Bool)onPlayEnd:(_Bool)arg1;
- (void)onProgressEnd;
- (void)onReadyForSight;
- (void)onResume;
- (void)onServiceEnterBackground:(id)arg1;
- (void)onServiceEnterForeground:(id)arg1;
- (void)onShareVideoToFriend:(id)arg1;
- (void)onShareVideoToTimeline:(_Bool)arg1;
- (void)onStack;
- (void)onStartFullPlay;
- (void)onStartPlayer;
- (void)playAttachVideoInFullScreen;
- (void)playInFullScreen;
- (void)playLongVideoAdInFullScreen;
- (void)playShortVideo;
- (_Bool)processClickToPlayAttachVideoInFullScreenMode;
- (void)reloadSight;
- (void)reloadSightPreviewImage;
- (void)removeObservers;
- (void)restartShortVideo;
- (void)setFrame:(struct CGRect)arg1;
- (_Bool)shouldAutoPlay;
- (_Bool)shouldShowDetailButton;
- (void)showCoverMask:(int)arg1;
- (void)showDownloadTooSlow;
- (_Bool)stopAtLastVideoFrameWhenPlayEnd;
- (void)stopPlayAttachVideo;
- (void)stopPlayShortVideo;
- (void)tryAddAdAttachVideoPlayCount;
- (void)tryAddAdShortVideoPlayCount;
- (void)tryLogAdAttachVideoStartPlayTime;
- (void)tryLogAdShortVideoStartPlayTime;
- (void)tryResetAdAttachVideoEndPlayTime;
- (void)tryResetAdShortVideoEndPlayTime;
- (void)tryRotateOrientation;
- (void)willAnimateRotation:(_Bool)arg1;
- (void)willMoveToSuperview:(id)arg1;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end
