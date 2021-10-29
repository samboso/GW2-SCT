#pragma once

#define LANGUAGE_CATEGORY(F)\
  F(General,=0)\
  F(Option_UI,)\
  F(Message,)\
  F(Scroll_Area_Option_UI,)\
  F(Receiver_Option_UI,)\
  F(Skill_Filter_Option_UI,)\
  F(Profile_Option_UI,)\
  F(messagePlayerOutgoingPhysical,)\
  F(messagePlayerOutgoingCrit,)\
  F(messagePlayerOutgoingBleeding,)\
  F(messagePlayerOutgoingBurning,)\
  F(messagePlayerOutgoingPoison,)\
  F(messagePlayerOutgoingConfusion,)\
  F(messagePlayerOutgoingRetaliation,)\
  F(messagePlayerOutgoingTorment,)\
  F(messagePlayerOutgoingDoT,)\
  F(messagePlayerOutgoingHeal,)\
  F(messagePlayerOutgoingHoT,)\
  F(messagePlayerOutgoingShieldGot,)\
  F(messagePlayerOutgoingShield,)\
  F(messagePlayerOutgoingBlock,)\
  F(messagePlayerOutgoingEvade,)\
  F(messagePlayerOutgoingInvulnerable,)\
  F(messagePlayerOutgoingMiss,)\
  F(messagePlayerIncomingPhysical,)\
  F(messagePlayerIncomingCrit,)\
  F(messagePlayerIncomingBleeding,)\
  F(messagePlayerIncomingBurning,)\
  F(messagePlayerIncomingPoison,)\
  F(messagePlayerIncomingConfusion,)\
  F(messagePlayerIncomingRetaliation,)\
  F(messagePlayerIncomingTorment,)\
  F(messagePlayerIncomingDoT,)\
  F(messagePlayerIncomingHeal,)\
  F(messagePlayerIncomingHoT,)\
  F(messagePlayerIncomingShieldGot,)\
  F(messagePlayerIncomingShield,)\
  F(messagePlayerIncomingBlock,)\
  F(messagePlayerIncomingEvade,)\
  F(messagePlayerIncomingInvulnerable,)\
  F(messagePlayerIncomingMiss,)\
  F(messagePetOutgoingPhysical,)\
  F(messagePetOutgoingCrit,)\
  F(messagePetOutgoingBleeding,)\
  F(messagePetOutgoingBurning,)\
  F(messagePetOutgoingPoison,)\
  F(messagePetOutgoingConfusion,)\
  F(messagePetOutgoingRetaliation,)\
  F(messagePetOutgoingTorment,)\
  F(messagePetOutgoingDoT,)\
  F(messagePetOutgoingHeal,)\
  F(messagePetOutgoingHoT,)\
  F(messagePetOutgoingShieldGot,)\
  F(messagePetOutgoingShield,)\
  F(messagePetOutgoingBlock,)\
  F(messagePetOutgoingEvade,)\
  F(messagePetOutgoingInvulnerable,)\
  F(messagePetOutgoingMiss,)\
  F(messagePetIncomingPhysical,)\
  F(messagePetIncomingCrit,)\
  F(messagePetIncomingBleeding,)\
  F(messagePetIncomingBurning,)\
  F(messagePetIncomingPoison,)\
  F(messagePetIncomingConfusion,)\
  F(messagePetIncomingRetaliation,)\
  F(messagePetIncomingTorment,)\
  F(messagePetIncomingDoT,)\
  F(messagePetIncomingHeal,)\
  F(messagePetIncomingHoT,)\
  F(messagePetIncomingShieldGot,)\
  F(messagePetIncomingShield,)\
  F(messagePetIncomingBlock,)\
  F(messagePetIncomingEvade,)\
  F(messagePetIncomingInvulnerable,)\
  F(messagePetIncomingMiss,)

#define LANGUAGE_KEY(F)\
  F(Outdated_Popup_Title,=0)\
  F(Outdated_Popup_Content,)\
  F(Outdated_Popup_Found_Version,)\
  F(Outdated_Popup_Required_Version,)\
  F(Outdated_Popup_Confirmation,)\
  F(Font,)\
  F(Font_Size,)\
  F(Font_Size_Type,)\
  F(Default_Font_Size,)\
  F(Default_Crit_Font_Size,)\
  F(Custom_Font_Size,)\
  F(Skill_Filter_Type_ID,)\
  F(Skill_Filter_Type_Name,)\
  F(Font_Master,)\
  F(Font_Default,)\
  F(Text_Align_Left,)\
  F(Text_Align_Center,)\
  F(Text_Align_Right,)\
  F(Text_Curve_Left,)\
  F(Text_Curve_Straight,)\
  F(Text_Curve_Right,)\
  F(Old_Save_Popup_Title,)\
  F(Old_Save_Popup_Content,)\
  F(Old_Save_Popup_Backup_Made,)\
  F(Old_Save_Popup_Confirmation,)\
  F(Unknown_Skill_Source,)\
  F(Unknown_Skill_Target,)\
  F(Unknown_Skill_Name,)\
  F(Default_Scroll_Area_Incoming,)\
  F(Default_Scroll_Area_Outgoing,)\
  F(Title,)\
  F(Menu_Bar_General,)\
  F(Menu_Bar_Scroll_Areas,)\
  F(Menu_Bar_Profession_Colors,)\
  F(Menu_Bar_Filtered_Skills,)\
  F(Menu_Bar_Skill_Icons,)\
  F(Menu_Bar_Profiles,)\
  F(General_Enabled,)\
  F(General_Scrolling_Speed,)\
  F(General_Scrolling_Speed_Toolip,)\
  F(General_Drop_Shadow,)\
  F(General_Max_Messages,)\
  F(General_Max_Messages_Toolip,)\
  F(General_Combine_Messages,)\
  F(General_Combine_Messages_Toolip,)\
  F(General_Self_Only_As_Incoming,)\
  F(General_Self_Only_As_Incoming_Toolip,)\
  F(General_Out_Only_For_Target,)\
  F(General_Out_Only_For_Target_Toolip,)\
  F(Scroll_Areas_New,)\
  F(Scroll_Areas_Name,)\
  F(Receiver_Name,) \
  F(Messages_Category,)\
  F(Messages_Category_Player_Out,)\
  F(Messages_Category_Player_In,)\
  F(Messages_Category_Pet_Out,)\
  F(Messages_Category_Pet_In,)\
  F(Messages_Type,)\
  F(Messages_Type_Physical,)\
  F(Messages_Type_Crit,)\
  F(Messages_Type_Bleeding,)\
  F(Messages_Type_Burning,)\
  F(Messages_Type_Poison,)\
  F(Messages_Type_Confusion,)\
  F(Messages_Type_Retaliation,)\
  F(Messages_Type_Torment,)\
  F(Messages_Type_Dot,)\
  F(Messages_Type_Heal,)\
  F(Messages_Type_Hot,)\
  F(Messages_Type_Shield_Receive,)\
  F(Messages_Type_Shield_Remove,)\
  F(Messages_Type_Block,)\
  F(Messages_Type_Evade,)\
  F(Messages_Type_Invulnerable,)\
  F(Messages_Type_Miss,)\
  F(Profession_Colors_Guardian,)\
  F(Profession_Colors_Warrior,)\
  F(Profession_Colors_Engineer,)\
  F(Profession_Colors_Ranger,)\
  F(Profession_Colors_Thief,)\
  F(Profession_Colors_Elementalist,)\
  F(Profession_Colors_Mesmer,)\
  F(Profession_Colors_Necromancer,)\
  F(Profession_Colors_Revenant,)\
  F(Profession_Colors_Undetectable,)\
  F(Skill_Icons_Warning,)\
  F(Skill_Icons_Enable,)\
  F(Skill_Icons_Preload_Description,)\
  F(Skill_Icons_Preload,)\
  F(Multiple_Sources,)\
  F(Number_Of_Hits,)\
  F(Horizontal_Offset,)\
  F(Vertical_Offset,)\
  F(Width,)\
  F(Height,)\
  F(Text_Align,)\
  F(Text_Flow,)\
  F(All_Receivers,)\
  F(New_Receiver,)\
  F(Template,)\
  F(Available_Parameters,)\
  F(Delete_Confirmation_Title,)\
  F(Delete_Confirmation_Content,)\
  F(Delete_Confirmation_Confirmation,)\
  F(Delete_Confirmation_Cancel,)\
  F(Parameter_Description_v,)\
  F(Parameter_Description_n,)\
  F(Parameter_Description_s,)\
  F(Parameter_Description_p,)\
  F(Parameter_Description_c,)\
  F(Parameter_Description_r,)\
  F(Parameter_Description_i,)\
  F(Default_Value,)\
  F(Profile_Description,)\
  F(Master_Profile,)\
  F(Character_Specific_Profile_Heading,)\
  F(Character_Specific_Profile_Enabled,)\
  F(Current_Profile_Heading,)\
  F(Current_Profile_Name,)\
  F(Create_Profile_Copy,)\
  F(Delete_Profile,)\
  F(Profile_Copy_Suffix,)
