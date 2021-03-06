//
//  FLPanelViewController.h
//  FishLampCocoa
//
//  Created by Mike Fullerton on 12/7/12.
//  Copyright (c) 2013 GreenTongue Software LLC, Mike Fullerton.. 
//  The FishLamp Framework is released under the MIT License: http://fishlamp.com/license 
//

#import "FLCocoaUIRequired.h"
#import "NSBundle+FLCurrentBundle.h"

@class FLPanelManager;
@class FLPanelViewController;

@protocol FLPanelArea <NSObject>
- (SDKView*) contentView;

@optional
- (void) panelDidAppear:(FLPanelViewController*) panel;
- (void) panelWillAppear:(FLPanelViewController*) panel;
- (void) panelWillDisappear:(FLPanelViewController*) panel;
- (void) panelDidDisappear:(FLPanelViewController*) panel;

@end

@protocol FLPanelButtons <FLPanelArea>
@property (readonly, strong, nonatomic) NSButton* nextButton;
@property (readonly, strong, nonatomic) NSButton* backButton;
@property (readonly, strong, nonatomic) NSButton* otherButton;
@end

@protocol FLPanelHeader <FLPanelArea>
@property (readonly, strong, nonatomic) NSTextField* promptTextField;

@end

@interface FLPanelViewController : NSViewController  {
@private
    NSString* _prompt;
    BOOL _canOpenNextPanel;
    __unsafe_unretained FLPanelManager* _panelManager;
    id<FLPanelButtons> _buttons;
    id<FLPanelHeader> _header;
    BOOL _panelFillsView;
    BOOL _authenticated;
    BOOL _independent;
    BOOL _hidden;
    BOOL _enabled;
    BOOL _selected;
    
    id _identifier;
    __unsafe_unretained id _delegate;

    id _alertViewController;
}

@property (readwrite, strong, nonatomic) id alertViewController;

@property (readwrite, strong, nonatomic) id identifier;

@property (readwrite, assign, nonatomic) id delegate;
@property (readonly, assign, nonatomic) FLPanelManager* panelManager;
@property (readwrite, strong, nonatomic) id<FLPanelButtons> buttons;
@property (readwrite, strong, nonatomic) id<FLPanelHeader> header;
@property (readwrite, strong, nonatomic) NSString* prompt;

@property (readwrite, assign, nonatomic) BOOL canOpenNextPanel;
@property (readwrite, assign, nonatomic) BOOL panelFillsView;

@property (readonly, assign, nonatomic, getter=isSelected) BOOL selected;
@property (readonly, assign, nonatomic, getter=isSelectable) BOOL selectable;

@property (readwrite, assign, nonatomic, getter=isAuthenticated) BOOL authenticated;
@property (readwrite, assign, nonatomic, getter=isIndependent) BOOL independent;
@property (readwrite, assign, nonatomic, getter=isHidden) BOOL hidden;
@property (readwrite, assign, nonatomic, getter=isEnabled) BOOL enabled;

- (void) panelWillAppear;
- (void) panelDidAppear;
- (void) panelWillDisappear;
- (void) panelDidDisappear;

- (void) respondToNextButton:(BOOL*) handledIt;
- (void) respondToBackButton:(BOOL*) handledIt;
- (void) respondToOtherButton:(BOOL*) handledIt;

- (void) didMoveToPanelManager:(FLPanelManager*) manager;

- (void) addPanelView:(SDKView*) panelView toPanelArea:(id<FLPanelArea>) panelArea animated:(BOOL) animated;

- (void) updateState:(id) state;

//- (void) showAlertWithError:(NSError*) error; 
//- (void) showAlertWithError:(NSError*) error withTitle:(NSString*) title;
//- (void) showAlertWithError:(NSError*) error withTitle:(NSString*) title withCaption:(NSString*) caption;
 
//- (void) didHideAlertWithError:(NSError*) error;

//- (void) showAlertWithTitle:(NSString*) title;
//- (void) showAlertWithTitle:(NSString*) title withCaption:(NSString*) caption;

+ (id) panelIdentifier;

@end



