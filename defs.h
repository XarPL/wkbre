#define CLASS_DECLARE_ITEM 0
#define CLASS_DEFINE_VALUE 1
#define CLASS_APPEARANCE_TAG 2
#define CLASS_ANIMATION_TAG 3
#define CLASS_USER 4
#define CLASS_LEVEL 5
#define CLASS_PLAYER 6
#define CLASS_CITY 7
#define CLASS_TOWN 8
#define CLASS_BUILDING 9
#define CLASS_CHARACTER 10
#define CLASS_CONTAINER 11
#define CLASS_FORMATION 12
#define CLASS_MARKER 13
#define CLASS_MISSILE 14
#define CLASS_PROP 15
#define CLASS_ARMY 16
#define CLASS_TERRAIN_ZONE 17
#define CLASS_COMMAND 18
#define CLASS_ACTION_SEQUENCE 19
#define CLASS_CHARACTER_LADDER 20
#define CLASS_USER_EXTENSION 21
#define CLASS_LEVEL_EXTENSION 22
#define CLASS_PLAYER_EXTENSION 23
#define CLASS_CITY_EXTENSION 24
#define CLASS_TOWN_EXTENSION 25
#define CLASS_BUILDING_EXTENSION 26
#define CLASS_CHARACTER_EXTENSION 27
#define CLASS_CONTAINER_EXTENSION 28
#define CLASS_FORMATION_EXTENSION 29
#define CLASS_MARKER_EXTENSION 30
#define CLASS_MISSILE_EXTENSION 31
#define CLASS_PROP_EXTENSION 32
#define CLASS_ARMY_EXTENSION 33
#define CLASS_DECLARE_ALIAS 34
#define CLASS_ASSOCIATE_CATEGORY 35
#define CLASS_DECLARE_ASSOCIATE_CATEGORY 36
#define CLASS_ORDER 37
#define CLASS_TASK 38
#define CLASS_REACTION 39
#define CLASS_DIPLOMATIC_LADDER 40
#define CLASS_DEFAULT_DIPLOMATIC_STATUS 41
#define CLASS_INDEV_EQUATION 42
#define CLASS_INDEV_OBJECT_FINDER_DEFINITION 43
#define CLASS_INDEV_ACTION_SEQUENCE 44
#define CLASS_EQUATION 45
#define CLASS_OBJECT_FINDER_DEFINITION 46
#define CLASS_TYPE_TAG 47
#define CLASS_OBJECT_CREATION 48
#define CLASS_GAME_EVENT 49
#define CLASS_PACKAGE_RECEIPT_TRIGGER 50
#define CLASS_VALUE_TAG 51
#define CLASS_DEFAULT_VALUE_TAG_INTERPRETATION 52
#define CLASS_ORDER_ASSIGNMENT 53
#define CLASS_ORDER_CATEGORY 54
#define CLASS_TASK_CATEGORY 55
#define CLASS_PACKAGE 56
#define CLASS_GAME_TEXT_WINDOW 57
#define CLASS_3D_CLIP 58
#define CLASS_CAMERA_PATH 59
#define CLASS_WORK_ORDER 60
#define CLASS_COMMISSION 61
#define CLASS_PLAN 62
#define CLASS_CONDITION 63
#define CLASS_INDIVIDUAL_ITEM 64
#define CLASS_NUM 65
extern char *CLASS_str[65];
#define CCOMMAND_BUTTON_ENABLED 0
#define CCOMMAND_BUTTON_DEPRESSED 1
#define CCOMMAND_BUTTON_HIGHLIGHTED 2
#define CCOMMAND_BLUEPRINT_TOOLTIP 3
#define CCOMMAND_START_SEQUENCE 4
#define CCOMMAND_NUM 5
extern char *CCOMMAND_str[5];
#define CBLUEPRINT_ITEM 0
#define CBLUEPRINT_STARTS_WITH_ITEM 1
#define CBLUEPRINT_BLUEPRINT_TOOLTIP 2
#define CBLUEPRINT_HAS_DYNAMIC_SHADOW 3
#define CBLUEPRINT_HAS_STATIC_SHADOW 4
#define CBLUEPRINT_MAP_SOUND_TAG 5
#define CBLUEPRINT_OFFERS_COMMAND 6
#define CBLUEPRINT_PHYSICAL_SUBTYPE 7
#define CBLUEPRINT_SCALE_APPEARANCE 8
#define CBLUEPRINT_MOVEMENT_BAND 9
#define CBLUEPRINT_INHERITS_FROM 10
#define CBLUEPRINT_MAP_TYPE_TAG 11
#define CBLUEPRINT_INTRINSIC_REACTION 12
#define CBLUEPRINT_INTERPRET_VALUE_TAG_AS 13
#define CBLUEPRINT_REPRESENT_AS 14
#define CBLUEPRINT_BUILDING_TYPE 15
#define CBLUEPRINT_CAN_SPAWN 16
#define CBLUEPRINT_MOVEMENT_SPEED_EQUATION 17
#define CBLUEPRINT_MISSILE_SPEED 18
#define CBLUEPRINT_NUM 19
extern char *CBLUEPRINT_str[19];
#define VALUE_CONSTANT 0
#define VALUE_DEFINED_VALUE 1
#define VALUE_ITEM_VALUE 2
#define VALUE_NUM_OBJECTS 3
#define VALUE_EQUATION_RESULT 4
#define VALUE_OBJECT_TYPE 5
#define VALUE_OBJECT_CLASS 6
#define VALUE_OBJECT_ID 7
#define VALUE_IS_SUBSET_OF 8
#define VALUE_WATER_BENEATH 9
#define VALUE_BLUEPRINT_ITEM_VALUE 10
#define VALUE_DISTANCE_BETWEEN 11
#define VALUE_DIPLOMATIC_STATUS_AT_LEAST 12
#define VALUE_CURRENTLY_DOING_ORDER 13
#define VALUE_TOTAL_ITEM_VALUE 14
#define VALUE_HAS_APPEARANCE 15
#define VALUE_CAN_REACH 16
#define VALUE_SAME_PLAYER 17
#define VALUE_ARE_ASSOCIATED 18
#define VALUE_IS_IDLE 19
#define VALUE_IS_DISABLED 20
#define VALUE_IS_MUSIC_PLAYING 21
#define VALUE_VALUE_TAG_INTERPRETATION 22
#define VALUE_TILE_ITEM 23
#define VALUE_NUM_REFERENCERS 24
#define VALUE_IS_ACCESSIBLE 25
#define VALUE_HAS_DIRECT_LINE_OF_SIGHT_TO 26
#define VALUE_FINDER_RESULTS_COUNT 27
#define VALUE_NUM_ASSOCIATES 28
#define VALUE_NUM_ASSOCIATORS 29
#define VALUE_INDEXED_ITEM_VALUE 30
#define VALUE_ANGLE_BETWEEN 31
#define VALUE_CURRENTLY_DOING_TASK 32
#define VALUE_IS_VISIBLE 33
#define VALUE_IS_DISCOVERED 34
#define VALUE_WITHIN_FORWARD_ARC 35
#define VALUE_BUILDING_TYPE 36
#define VALUE_BUILDING_TYPE_OPERAND 37
#define VALUE_AI_CONTROLLED 38
#define VALUE_MAP_WIDTH 39
#define VALUE_MAP_DEPTH 40
#define VALUE_GRADIENT_IN_FRONT 41
#define VALUE_CAN_AFFORD_COMMISSION 42
#define VALUE_DISTANCE_BETWEEN_INCLUDING_RADIUS 43
#define VALUE_COULD_REACH 44
#define VALUE_NUM_ORDERS 45
#define VALUE_CAN_TRAVERSE_NEIGHBOURING_TILE 46
#define VALUE_NUM 47
extern char *VALUE_str[47];
#define ENODE_ADDITION 0
#define ENODE_SUBTRACTION 1
#define ENODE_MULTIPLICATION 2
#define ENODE_DIVISION 3
#define ENODE_ABSOLUTE_VALUE 4
#define ENODE_MAX 5
#define ENODE_MIN 6
#define ENODE_AND 7
#define ENODE_OR 8
#define ENODE_NOT 9
#define ENODE_IS_ZERO 10
#define ENODE_IS_POSITIVE 11
#define ENODE_IS_NEGATIVE 12
#define ENODE_EQUALS 13
#define ENODE_LESS_THAN 14
#define ENODE_LESS_THAN_OR_EQUAL_TO 15
#define ENODE_GREATER_THAN 16
#define ENODE_GREATER_THAN_OR_EQUAL_TO 17
#define ENODE_RANDOM_UP_TO 18
#define ENODE_RANDOM_INTEGER 19
#define ENODE_RANDOM_RANGE 20
#define ENODE_IF_THEN_ELSE 21
#define ENODE_IS_BETWEEN 22
#define ENODE_FRONT_BACK_LEFT_RIGHT 23
#define ENODE_TRUNC 24
#define ENODE_NEGATE 25
#define ENODE_ROUND 26
#define ENODE_NUM 27
extern char *ENODE_str[27];
#define FINDER_SPECIFIC_ID 0
#define FINDER_SELF 1
#define FINDER_SEQUENCE_EXECUTOR 2
#define FINDER_TARGET 3
#define FINDER_PLAYER 4
#define FINDER_CONTROLLER 5
#define FINDER_CREATOR 6
#define FINDER_CANDIDATE 7
#define FINDER_ALIAS 8
#define FINDER_ASSOCIATES 9
#define FINDER_ASSOCIATORS 10
#define FINDER_PLAYERS 11
#define FINDER_LEVEL 12
#define FINDER_PACKAGE_SENDER 13
#define FINDER_TILE_RADIUS 14
#define FINDER_METRE_RADIUS 15
#define FINDER_NEAREST_TO_SATISFY 16
#define FINDER_DISABLED_ASSOCIATES 17
#define FINDER_GRADE_SELECT 18
#define FINDER_GRADE_SELECT_CANDIDATES 19
#define FINDER_REFERENCERS 20
#define FINDER_ORDER_GIVER 21
#define FINDER_CHAIN_ORIGINAL_SELF 22
#define FINDER_PACKAGE_RELATED_PARTY 23
#define FINDER_BEING_TRANSFERRED_TO_ME 24
#define FINDER_DISCOVERED_UNITS 25
#define FINDER_USER 26
#define FINDER_AG_SELECTION 27
#define FINDER_UNION 28
#define FINDER_INTERSECTION 29
#define FINDER_CHAIN 30
#define FINDER_ALTERNATIVE 31
#define FINDER_RESULTS 32
#define FINDER_SUBORDINATES 33
#define FINDER_FILTER 34
#define FINDER_FILTER_FIRST 35
#define FINDER_FILTER_CANDIDATES 36
#define FINDER_NEAREST_CANDIDATE 37
#define FINDER_NUM 38
extern char *FINDER_str[38];
#define POSITION_CENTRE_OF_MAP 0
#define POSITION_LOCATION_OF 1
#define POSITION_OUT_AT_ANGLE 2
#define POSITION_NEAREST_VALID_POSITION_FOR 3
#define POSITION_NEAREST_ATTACHMENT_POINT 4
#define POSITION_ABSOLUTE_POSITION 5
#define POSITION_SPAWN_TILE_POSITION 6
#define POSITION_THIS_SIDE_OF 7
#define POSITION_THE_OTHER_SIDE_OF 8
#define POSITION_TOWARDS 9
#define POSITION_AWAY_FROM 10
#define POSITION_IN_FRONT_OF 11
#define POSITION_FIRING_ATTACHMENT_POINT 12
#define POSITION_NEAREST_VALID_STAMPDOWN_POS 13
#define POSITION_OFFSET_FROM 14
#define POSITION_DESTINATION_OF 15
#define POSITION_MATCHING_OFFSET 16
#define POSITION_NUM 17
extern char *POSITION_str[17];
#define ACTION_REMOVE 0
#define ACTION_CREATE_OBJECT 1
#define ACTION_EXECUTE_SEQUENCE 2
#define ACTION_REPEAT_SEQUENCE 3
#define ACTION_SET_ITEM 4
#define ACTION_INCREASE_ITEM 5
#define ACTION_DECREASE_ITEM 6
#define ACTION_UPON_CONDITION 7
#define ACTION_CREATE_OBJECT_VIA 8
#define ACTION_SEND_EVENT 9
#define ACTION_CLEAR_ALIAS 10
#define ACTION_ASSIGN_ALIAS 11
#define ACTION_UNASSIGN_ALIAS 12
#define ACTION_DISABLE 13
#define ACTION_ENABLE 14
#define ACTION_CLEAR_ASSOCIATES 15
#define ACTION_REGISTER_ASSOCIATES 16
#define ACTION_DEREGISTER_ASSOCIATES 17
#define ACTION_EXECUTE_ONE_AT_RANDOM 18
#define ACTION_TRACE_VALUE 19
#define ACTION_TRACE_FINDER_RESULTS 20
#define ACTION_TERMINATE_THIS_TASK 21
#define ACTION_TRACE 22
#define ACTION_ASSIGN_ORDER_VIA 23
#define ACTION_TERMINATE_TASK 24
#define ACTION_TERMINATE_ORDER 25
#define ACTION_TERMINATE_THIS_ORDER 26
#define ACTION_CANCEL_ORDER 27
#define ACTION_TRANSFER_CONTROL 28
#define ACTION_SWITCH_APPEARANCE 29
#define ACTION_CONVERT_TO 30
#define ACTION_CONVERT_ACCORDING_TO_TAG 31
#define ACTION_EXECUTE_SEQUENCE_AFTER_DELAY 32
#define ACTION_EXECUTE_SEQUENCE_OVER_PERIOD 33
#define ACTION_REPEAT_SEQUENCE_OVER_PERIOD 34
#define ACTION_ADD_REACTION 35
#define ACTION_REMOVE_REACTION 36
#define ACTION_CHANGE_REACTION_PROFILE 37
#define ACTION_SET_SCALE 38
#define ACTION_TERMINATE 39
#define ACTION_SINK_AND_REMOVE 40
#define ACTION_SEND_PACKAGE 41
#define ACTION_SET_SELECTABLE 42
#define ACTION_SET_TARGETABLE 43
#define ACTION_SET_RENDERABLE 44
#define ACTION_SWITCH_CONDITION 45
#define ACTION_SWITCH_HIGHEST 46
#define ACTION_DISPLAY_GAME_TEXT_WINDOW 47
#define ACTION_HIDE_GAME_TEXT_WINDOW 48
#define ACTION_HIDE_CURRENT_GAME_TEXT_WINDOW 49
#define ACTION_PLAY_CLIP 50
#define ACTION_SNAP_CAMERA_TO_POSITION 51
#define ACTION_FACE_TOWARDS 52
#define ACTION_IDENTIFY_AND_MARK_CLUSTERS 53
#define ACTION_STORE_CAMERA_POSITION 54
#define ACTION_SNAP_CAMERA_TO_STORED_POSITION 55
#define ACTION_SET_INDEXED_ITEM 56
#define ACTION_INCREASE_INDEXED_ITEM 57
#define ACTION_DECREASE_INDEXED_ITEM 58
#define ACTION_SET_RECONNAISSANCE 59
#define ACTION_ENABLE_DIPLOMATIC_REPORT_WINDOW 60
#define ACTION_DISABLE_DIPLOMATIC_REPORT_WINDOW 61
#define ACTION_ENABLE_TRIBUTES_WINDOW 62
#define ACTION_DISABLE_TRIBUTES_WINDOW 63
#define ACTION_COPY_FACING_OF 64
#define ACTION_TELEPORT 65
#define ACTION_LOCK_TIME 66
#define ACTION_UNLOCK_TIME 67
#define ACTION_REMOVE_MULTIPLAYER_PLAYER 68
#define ACTION_REEVALUATE_TASK_TARGET 69
#define ACTION_CREATE_FORMATION 70
#define ACTION_CREATE_FORMATION_REFERENCE 71
#define ACTION_CHANGE_DIPLOMATIC_STATUS 72
#define ACTION_DISBAND_FORMATION 73
#define ACTION_LEAVE_FORMATION 74
#define ACTION_PLAY_CAMERA_PATH 75
#define ACTION_STOP_CAMERA_PATH_PLAYBACK 76
#define ACTION_INTERPOLATE_CAMERA_TO_POSITION 77
#define ACTION_SKIP_CAMERA_PATH_PLAYBACK 78
#define ACTION_STOP_SOUND 79
#define ACTION_PLAY_SOUND 80
#define ACTION_PLAY_SOUND_AT_POSITION 81
#define ACTION_PLAY_SPECIAL_EFFECT 82
#define ACTION_PLAY_SPECIAL_EFFECT_BETWEEN 83
#define ACTION_PLAY_ANIMATION_IF_IDLE 84
#define ACTION_ATTACH_SPECIAL_EFFECT 85
#define ACTION_ATTACH_LOOPING_SPECIAL_EFFECT 86
#define ACTION_DETACH_LOOPING_SPECIAL_EFFECT 87
#define ACTION_REVEAL_FOG_OF_WAR 88
#define ACTION_COLLAPSING_CIRCLE_ON_MINIMAP 89
#define ACTION_SHOW_BLINKING_DOT_ON_MINIMAP 90
#define ACTION_ENABLE_GAME_INTERFACE 91
#define ACTION_DISABLE_GAME_INTERFACE 92
#define ACTION_SET_ACTIVE_MISSION_OBJECTIVES 93
#define ACTION_SHOW_MISSION_OBJECTIVES_ENTRY 94
#define ACTION_SHOW_MISSION_OBJECTIVES_ENTRY_INACTIVE 95
#define ACTION_HIDE_MISSION_OBJECTIVES_ENTRY 96
#define ACTION_TRACK_OBJECT_POSITION_FROM_MISSION_OBJECTIVES_ENTRY 97
#define ACTION_STOP_INDICATING_POSITION_OF_MISSION_OBJECTIVES_ENTRY 98
#define ACTION_FORCE_PLAY_MUSIC 99
#define ACTION_ADOPT_APPEARANCE_FOR 100
#define ACTION_ADOPT_DEFAULT_APPEARANCE_FOR 101
#define ACTION_ACTIVATE_COMMISSION 102
#define ACTION_DEACTIVATE_COMMISSION 103
#define ACTION_SWITCH_ON_INTENSITY_MAP 104
#define ACTION_FADE_STOP_MUSIC 105
#define ACTION_DECLINE_DIPLOMATIC_OFFER 106
#define ACTION_SEND_CHAT_MESSAGE 107
#define ACTION_MAKE_DIPLOMATIC_OFFER 108
#define ACTION_SET_CHAT_PERSONALITY 109
#define ACTION_UPDATE_USER_PROFILE 110
#define ACTION_UNLOCK_LEVEL 111
#define ACTION_BOOT_LEVEL 112
#define ACTION_EXIT_TO_MAIN_MENU 113
#define ACTION_CONQUER_LEVEL 114
#define ACTION_DISPLAY_LOAD_GAME_MENU 115
#define ACTION_PLAY_MUSIC 116
#define ACTION_NUM 117
extern char *ACTION_str[117];
#define OBJCREATE_TYPE_TO_CREATE 0
#define OBJCREATE_MAPPED_TYPE_TO_CREATE 1
#define OBJCREATE_MATCH_APPEARANCE_OF 2
#define OBJCREATE_CONTROLLER 3
#define OBJCREATE_CREATE_AT 4
#define OBJCREATE_POST_CREATION_SEQUENCE 5
#define OBJCREATE_NUM 6
extern char *OBJCREATE_str[6];
#define SAVEGAME_DELAYED_SEQUENCE_EXECUTION 0
#define SAVEGAME_EXECUTE_SEQUENCE_OVER_PERIOD 1
#define SAVEGAME_REPEAT_SEQUENCE_OVER_PERIOD 2
#define SAVEGAME_GAME_SET 3
#define SAVEGAME_NEXT_UNIQUE_ID 4
#define SAVEGAME_PREDEC 5
#define SAVEGAME_LEVEL 6
#define SAVEGAME_GAME_TYPE 7
#define SAVEGAME_PART_OF_CAMPAIGN 8
#define SAVEGAME_SERVER_NAME 9
#define SAVEGAME_NUM_HUMAN_PLAYERS 10
#define SAVEGAME_UPDATE_ID 11
#define SAVEGAME_NEXT_UPDATE_TIME_STAMP 12
#define SAVEGAME_CURRENT_TIME 13
#define SAVEGAME_PREVIOUS_TIME 14
#define SAVEGAME_ELAPSED_TIME 15
#define SAVEGAME_PAUSED 16
#define SAVEGAME_LOCK_COUNT 17
#define SAVEGAME_CLIENT_STATE 18
#define SAVEGAME_NUM 19
extern char *SAVEGAME_str[19];
#define GAMEOBJ_POSITION 0
#define GAMEOBJ_ORIENTATION 1
#define GAMEOBJ_ITEM 2
#define GAMEOBJ_SUBTYPE 3
#define GAMEOBJ_APPEARANCE 4
#define GAMEOBJ_COLOUR_INDEX 5
#define GAMEOBJ_ORDER_CONFIGURATION 6
#define GAMEOBJ_SCALE 7
#define GAMEOBJ_PLAYER 8
#define GAMEOBJ_CITY 9
#define GAMEOBJ_TOWN 10
#define GAMEOBJ_BUILDING 11
#define GAMEOBJ_CHARACTER 12
#define GAMEOBJ_CONTAINER 13
#define GAMEOBJ_FORMATION 14
#define GAMEOBJ_MARKER 15
#define GAMEOBJ_MISSILE 16
#define GAMEOBJ_PROP 17
#define GAMEOBJ_ARMY 18
#define GAMEOBJ_TERRAIN_ZONE 19
#define GAMEOBJ_MAP 20
#define GAMEOBJ_RECONNAISSANCE 21
#define GAMEOBJ_FOG_OF_WAR 22
#define GAMEOBJ_RECTANGLE 23
#define GAMEOBJ_ALIAS 24
#define GAMEOBJ_ASSOCIATE 25
#define GAMEOBJ_TERMINATED 26
#define GAMEOBJ_PLAYER_TERMINATED 27
#define GAMEOBJ_DISABLE_COUNT 28
#define GAMEOBJ_INDIVIDUAL_REACTION 29
#define GAMEOBJ_DIPLOMATIC_STATUS_BETWEEN 30
#define GAMEOBJ_NAME 31
#define GAMEOBJ_PARAM_BLOCK 32
#define GAMEOBJ_NEXT_UNIQUE_ID 33
#define GAMEOBJ_TILES 34
#define GAMEOBJ_SELECTABLE 35
#define GAMEOBJ_TARGETABLE 36
#define GAMEOBJ_RENDERABLE 37
#define GAMEOBJ_AI_CONTROLLER 38
#define GAMEOBJ_DIPLOMATIC_OFFER 39
#define GAMEOBJ_NUM 40
extern char *GAMEOBJ_str[40];
#define OBJTYPE_USER 0
#define OBJTYPE_LEVEL 1
#define OBJTYPE_PLAYER 2
#define OBJTYPE_CITY 3
#define OBJTYPE_TOWN 4
#define OBJTYPE_BUILDING 5
#define OBJTYPE_CHARACTER 6
#define OBJTYPE_CONTAINER 7
#define OBJTYPE_FORMATION 8
#define OBJTYPE_MARKER 9
#define OBJTYPE_MISSILE 10
#define OBJTYPE_PROP 11
#define OBJTYPE_ARMY 12
#define OBJTYPE_TERRAIN_ZONE 13
#define OBJTYPE_NUM 14
extern char *OBJTYPE_str[14];
#define SETTING_GAME_DIR 0
#define SETTING_FAR_Z_VALUE 1
#define SETTING_HARDWARE_VERTEX_PROCESSING 2
#define SETTING_OCCLUSION_RATE 3
#define SETTING_VSYNC 4
#define SETTING_TEXTURE_COMPRESSION 5
#define SETTING_MAP_MAX_PART_SIZE 6
#define SETTING_FOG 7
#define SETTING_FONT 8
#define SETTING_HARDWARE_CURSOR 9
#define SETTING_FULLSCREEN 10
#define SETTING_SCREEN_SIZE 11
#define SETTING_MULTI_BCP 12
#define SETTING_RENDERER 13
#define SETTING_USE_MAP_TEXTURE_DATABASE 14
#define SETTING_MESH_BATCHING 15
#define SETTING_ANIMATED_MODELS 16
#define SETTING_VERTICAL_FOV 17
#define SETTING_PRELOAD_ALL_MODELS 18
#define SETTING_ENABLE_GAMEPLAY_SHORTCUTS 19
#define SETTING_SHOW_TIME_OBJ_INFO 20
#define SETTING_ENABLE_GAMESET_TRACING 21
#define SETTING_NUM 22
extern char *SETTING_str[22];
#define STASK_TRIGGER 0
#define STASK_TARGET 1
#define STASK_PROXIMITY 2
#define STASK_PROXIMITY_SATISFIED 3
#define STASK_LAST_DESTINATION_VALID 4
#define STASK_FIRST_EXECUTION 5
#define STASK_TRIGGERS_STARTED 6
#define STASK_PROCESS_STATE 7
#define STASK_TASK_ID 8
#define STASK_START_SEQUENCE_EXECUTED 9
#define STASK_SPAWN_BLUEPRINT 10
#define STASK_COST_DEDUCTED 11
#define STASK_DESTINATION 12
#define STASK_FACE_TOWARDS 13
#define STASK_START_TIME 14
#define STASK_INITIAL_POSITION 15
#define STASK_INITIAL_VELOCITY 16
#define STASK_NUM 17
extern char *STASK_str[17];
#define SORDER_TASK 0
#define SORDER_PROCESS_STATE 1
#define SORDER_CYCLED 2
#define SORDER_ORDER_ID 3
#define SORDER_UNIQUE_TASK_ID 4
#define SORDER_CURRENT_TASK 5
#define SORDER_NUM 6
extern char *SORDER_str[6];
#define PDEVENT_ON_STAMPDOWN 0
#define PDEVENT_ON_LEVEL_START 1
#define PDEVENT_ON_CONTROL_TRANSFERRED 2
#define PDEVENT_ON_CONVERSION_END 3
#define PDEVENT_ON_TERMINATION 4
#define PDEVENT_ON_DESTRUCTION 5
#define PDEVENT_ON_SPAWN 6
#define PDEVENT_ON_SHARE_TILE 7
#define PDEVENT_ON_IDLE 8
#define PDEVENT_ON_BUSY 9
#define PDEVENT_NUM 10
extern char *PDEVENT_str[10];
extern char* PDEVENT_tab0[10];
#define ORDTSKTYPE_OBJECT_REFERENCE 0
#define ORDTSKTYPE_SPAWN 1
#define ORDTSKTYPE_UPGRADE 2
#define ORDTSKTYPE_MOVE 3
#define ORDTSKTYPE_FACE_TOWARDS 4
#define ORDTSKTYPE_MISSILE 5
#define ORDTSKTYPE_ATTACK 6
#define ORDTSKTYPE_BUILD 7
#define ORDTSKTYPE_REPAIR 8
#define ORDTSKTYPE_FORMATION_CREATE 9
#define ORDTSKTYPE_NUM 10
extern char *ORDTSKTYPE_str[10];
#define CORDER_USE_TASK 0
#define CORDER_FLAG 1
#define CORDER_CLASS_TYPE 2
#define CORDER_IN_ORDER_CATEGORY 3
#define CORDER_INITIALISATION_SEQUENCE 4
#define CORDER_START_SEQUENCE 5
#define CORDER_SUSPENSION_SEQUENCE 6
#define CORDER_RESUMPTION_SEQUENCE 7
#define CORDER_CANCELLATION_SEQUENCE 8
#define CORDER_TERMINATION_SEQUENCE 9
#define CORDER_NUM 10
extern char *CORDER_str[10];
#define CTASK_CLASS_TYPE 0
#define CTASK_IN_TASK_CATEGORY 1
#define CTASK_TASK_TARGET 2
#define CTASK_USE_PREVIOUS_TASK_TARGET 3
#define CTASK_PROXIMITY_REQUIREMENT 4
#define CTASK_FLAG 5
#define CTASK_INITIALISATION_SEQUENCE 6
#define CTASK_START_SEQUENCE 7
#define CTASK_SUSPENSION_SEQUENCE 8
#define CTASK_RESUMPTION_SEQUENCE 9
#define CTASK_CANCELLATION_SEQUENCE 10
#define CTASK_TERMINATION_SEQUENCE 11
#define CTASK_PROXIMITY_SATISFIED_SEQUENCE 12
#define CTASK_PROXIMITY_DISSATISFIED_SEQUENCE 13
#define CTASK_MOVEMENT_STARTED_SEQUENCE 14
#define CTASK_MOVEMENT_COMPLETED_SEQUENCE 15
#define CTASK_TRIGGER 16
#define CTASK_SYNCH_ANIMATION_TO_FRACTION 17
#define CTASK_REJECT_TARGET_IF_IT_IS_TERMINATED 18
#define CTASK_TERMINATE_ENTIRE_ORDER_IF_NO_TARGET 19
#define CTASK_IDENTIFY_TARGET_EACH_CYCLE 20
#define CTASK_PLAY_ANIMATION 21
#define CTASK_PLAY_ANIMATION_ONCE 22
#define CTASK_NUM 23
extern char *CTASK_str[23];
#define ORDERASSIGNMODE_FORGET_EVERYTHING_ELSE 0
#define ORDERASSIGNMODE_DO_FIRST 1
#define ORDERASSIGNMODE_DO_LAST 2
#define ORDERASSIGNMODE_NUM 3
extern char *ORDERASSIGNMODE_str[3];
#define CORDERASSIGN_ORDER_ASSIGNMENT_MODE 0
#define CORDERASSIGN_ORDER_TO_ASSIGN 1
#define CORDERASSIGN_ORDER_TARGET 2
#define CORDERASSIGN_NUM 3
extern char *CORDERASSIGN_str[3];
#define TASKTRIGGER_TIMER 0
#define TASKTRIGGER_ANIMATION_LOOP 1
#define TASKTRIGGER_UNINTERRUPTIBLE_ANIMATION_LOOP 2
#define TASKTRIGGER_ATTACHMENT_POINT 3
#define TASKTRIGGER_COLLISION 4
#define TASKTRIGGER_STRUCK_FLOOR 5
#define TASKTRIGGER_NUM 6
extern char *TASKTRIGGER_str[6];
#define DISTCALCMODE_3D 0
#define DISTCALCMODE_HORIZONTAL 1
#define DISTCALCMODE_VERTICAL 2
#define DISTCALCMODE_NUM 3
extern char *DISTCALCMODE_str[3];
#define OBJFINDCOND_SAME_PLAYER_UNITS 0
#define OBJFINDCOND_ALLIED_UNITS 1
#define OBJFINDCOND_ENEMY_UNITS 2
#define OBJFINDCOND_ORIGINAL_SAME_PLAYER_UNITS 3
#define OBJFINDCOND_ORIGINAL_ALLIED_UNITS 4
#define OBJFINDCOND_ORIGINAL_ENEMY_UNITS 5
#define OBJFINDCOND_BUILDINGS_ONLY 6
#define OBJFINDCOND_CHARACTERS_ONLY 7
#define OBJFINDCOND_CHARACTERS_AND_BUILDINGS_ONLY 8
#define OBJFINDCOND_NUM 9
extern char *OBJFINDCOND_str[9];
#define PACKAGE_ITEM_MOD_REPLACE 0
#define PACKAGE_ITEM_MOD_INCREASE 1
#define PACKAGE_ITEM_MOD_REDUCE 2
#define PACKAGE_ITEM_MOD_NUM 3
extern char *PACKAGE_ITEM_MOD_str[3];
#define GTW_BUTTON_WINDOW_ACTION_CLOSE_WINDOW 0
#define GTW_BUTTON_WINDOW_ACTION_MOVE_PREVIOUS_PAGE 1
#define GTW_BUTTON_WINDOW_ACTION_MOVE_NEXT_PAGE 2
#define GTW_BUTTON_WINDOW_ACTION_MOVE_FIRST_PAGE 3
#define GTW_BUTTON_WINDOW_ACTION_NUM 4
extern char *GTW_BUTTON_WINDOW_ACTION_str[4];
#define SREQSTATE_COMPLETE 0
#define SREQSTATE_ACTIVE 1
#define SREQSTATE_STALLED 2
#define SREQSTATE_BLOCKED 3
#define SREQSTATE_NUM 4
extern char *SREQSTATE_str[4];
#define SREQDETAILEDSTATE_OK 0
#define SREQDETAILEDSTATE_WAIT_CONDITION_FAILED 1
#define SREQDETAILEDSTATE_RESOURCE_REQUIRED_RESERVED 2
#define SREQDETAILEDSTATE_IMPOSSIBLE_CONDITION_FAILED 3
#define SREQDETAILEDSTATE_NO_SPAWN_LOCATION_FOUND 4
#define SREQDETAILEDSTATE_NO_SPAWN_LOCATIONS_IDLE 5
#define SREQDETAILEDSTATE_NO_UPGRADE_LOCATION_FOUND 6
#define SREQDETAILEDSTATE_NO_UPGRADE_LOCATIONS_IDLE 7
#define SREQDETAILEDSTATE_CANT_AFFORD 8
#define SREQDETAILEDSTATE_UNPROCESSED 9
#define SREQDETAILEDSTATE_SPAWN_ORDER_ASSIGNMENT_FAILED 10
#define SREQDETAILEDSTATE_UPGRADE_ORDER_ASSIGNMENT_FAILED 11
#define SREQDETAILEDSTATE_FOUNDATION_CREATION_FAILED 12
#define SREQDETAILEDSTATE_NO_VALID_POSITION 13
#define SREQDETAILEDSTATE_NUM 14
extern char *SREQDETAILEDSTATE_str[14];
#define SREQUIREMENTCLASS_BUILDING_REQUIREMENT 0
#define SREQUIREMENTCLASS_CHARACTER_REQUIREMENT 1
#define SREQUIREMENTCLASS_UPGRADE_REQUIREMENT 2
#define SREQUIREMENTCLASS_NUM 3
extern char *SREQUIREMENTCLASS_str[3];
#define BUILDINGTYPE_GATEHOUSE 0
#define BUILDINGTYPE_WALL 1
#define BUILDINGTYPE_WALL_CROSSROADS 2
#define BUILDINGTYPE_WALL_CORNER_IN 3
#define BUILDINGTYPE_WALL_CORNER_OUT 4
#define BUILDINGTYPE_RURAL_CENTRE 5
#define BUILDINGTYPE_CIVIC_CENTRE 6
#define BUILDINGTYPE_RURAL 7
#define BUILDINGTYPE_CIVIC 8
#define BUILDINGTYPE_TOWER 9
#define BUILDINGTYPE_TOWER_CORNER_IN 10
#define BUILDINGTYPE_TOWER_CORNER_OUT 11
#define BUILDINGTYPE_NUM 12
extern char *BUILDINGTYPE_str[12];
