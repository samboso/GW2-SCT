#include "Message.h"
#include <iostream>
#include <sstream>
#include "Language.h"

#define COMBINE_FUNCTION(NAME) std::function<bool(std::vector<std::shared_ptr<MessageData>>, std::vector<std::shared_ptr<MessageData>>)> NAME = [](std::vector<std::shared_ptr<MessageData>> srcData, std::vector<std::shared_ptr<MessageData>> targetData)
#define PARAMETER_FUNCTION(NAME) std::function<std::string(std::vector<std::shared_ptr<MessageData>>)> NAME = [](std::vector<std::shared_ptr<MessageData>> data)

namespace GW2_SCT {
	COMBINE_FUNCTION(combineFunctionSkillId) {
		if (srcData.begin() != srcData.end() && targetData.begin() != targetData.end()) {
			if ((*(srcData.begin()))->skillId == (*(targetData.begin()))->skillId) {
				return true;
			}
		}
		return false;
	};

	COMBINE_FUNCTION(combineFunctionEntityId) {
		if (srcData.begin() != srcData.end() && targetData.begin() != targetData.end()) {
			if ((*(srcData.begin()))->entityId == (*(targetData.begin()))->entityId) {
				return true;
			}
		}
		return false;
	};

	COMBINE_FUNCTION(combineFunctionOtherEntityId) {
		if (srcData.begin() != srcData.end() && targetData.begin() != targetData.end()) {
			if ((*(srcData.begin()))->otherEntityId == (*(targetData.begin()))->otherEntityId) {
				return true;
			}
		}
		return false;
	};

	PARAMETER_FUNCTION(parameterFunctionValue) {
		int32_t value = 0;
		for (auto i : data) {
			value += i->value;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionBuffValue) {
		int32_t value = 0;
		for (auto i : data) {
			value += i->buffValue;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionNegativeValue) {
		int32_t value = 0;
		for (auto i : data) {
			value -= i->value;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionOverstackValue) {
		int32_t value = 0;
		for (auto i : data) {
			value += i->overstack_value;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionNegativeBuffValue) {
		int32_t value = 0;
		for (auto i : data) {
			value -= i->buffValue;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionOverstackBuffValue) {
		int32_t value = 0;
		for (auto i : data) {
			value += i->overstack_value;
		}
		return std::to_string(value);
	};

	PARAMETER_FUNCTION(parameterFunctionEntityName) {
		if (data.size() > 1) {
			std::string ret = std::string(data[0]->entityName);
			for (std::shared_ptr<MessageData> temp : data) {
				if (strcmp(temp->entityName, ret.c_str()) != 0) {
					ret = std::string(langString(GW2_SCT::LanguageCategory::Message, GW2_SCT::LanguageKey::Multiple_Sources));
					break;
				}
			}
			return ret;
		}
		if (data.size() == 1 && data[0]->entityName != nullptr) {
			return std::string(data[0]->entityName);
		}
		return std::string("");
	};

	PARAMETER_FUNCTION(parameterFunctionOtherEntityName) {
		if (data.size() >= 1 && data[0]->otherEntityName != nullptr) {
			return std::string(data[0]->otherEntityName);
		}
		return std::string("");
	};

	PARAMETER_FUNCTION(parameterFunctionSkillName) {
		if (data.begin() != data.end() && data[0]->skillName != nullptr) {
			return std::string(data[0]->skillName);
		}
		return std::string("");
	};

	PARAMETER_FUNCTION(parameterFunctionSkillIcon) {
		if (Options::get()->skillIconsEnabled && data.begin() != data.end()) {
			return std::string("[icon=" + std::to_string(data[0]->skillId) + "][/icon]");
		}
		return std::string("");
	};

	PARAMETER_FUNCTION(parameterFunctionEntityProfessionName) {
		if (data.begin() != data.end() && data[0]->skillName != nullptr) {
			std::string professionName;
			switch (data[0]->entityProf)
			{
			case PROFESSION_GUARDIAN:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Guardian));
				break;
			case PROFESSION_WARRIOR:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Warrior));
				break;
			case PROFESSION_ENGINEER:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Engineer));
				break;
			case PROFESSION_RANGER:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Ranger));
				break;
			case PROFESSION_THIEF:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Thief));
				break;
			case PROFESSION_ELEMENTALIST:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Elementalist));
				break;
			case PROFESSION_MESMER:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Mesmer));
				break;
			case PROFESSION_NECROMANCER:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Necromancer));
				break;
			case PROFESSION_REVENANT:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Revenant));
				break;
			default:
				professionName = std::string(GW2_SCT::Language::get(GW2_SCT::LanguageCategory::Option_UI, GW2_SCT::LanguageKey::Profession_Colors_Undetectable));
				break;
			}
			return professionName;
		}
		return std::string("");
	};

	PARAMETER_FUNCTION(parameterFunctionEntityProfessionColor) {
		std::string professionColor;
		switch (data[0]->entityProf)
		{
		case PROFESSION_GUARDIAN:
			professionColor = GW2_SCT::Options::get()->professionColorGuardian;
			break;
		case PROFESSION_WARRIOR:
			professionColor = GW2_SCT::Options::get()->professionColorWarrior;
			break;
		case PROFESSION_ENGINEER:
			professionColor = GW2_SCT::Options::get()->professionColorEngineer;
			break;
		case PROFESSION_RANGER:
			professionColor = GW2_SCT::Options::get()->professionColorRanger;
			break;
		case PROFESSION_THIEF:
			professionColor = GW2_SCT::Options::get()->professionColorThief;
			break;
		case PROFESSION_ELEMENTALIST:
			professionColor = GW2_SCT::Options::get()->professionColorElementalist;
			break;
		case PROFESSION_MESMER:
			professionColor = GW2_SCT::Options::get()->professionColorMesmer;
			break;
		case PROFESSION_NECROMANCER:
			professionColor = GW2_SCT::Options::get()->professionColorNecromancer;
			break;
		case PROFESSION_REVENANT:
			professionColor = GW2_SCT::Options::get()->professionColorRevenant;
			break;
		default:
			professionColor = GW2_SCT::Options::get()->professionColorDefault;
			break;
		}
		return professionColor;
	};

	std::map<MessageCategory, std::map<MessageType, MessageHandler>> EventMessage::messageHandlers = {
		{ MessageCategory::PLAYER_OUT, {
			{ MessageType::PHYSICAL,       { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CRIT,           { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeValue  }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLEEDING,       { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BURNING,        { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::POISON,         { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CONFUSION,      { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::RETALIATION,    { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::TORMENT,        { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::DOT,            { { combineFunctionSkillId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HEAL,           { { combineFunctionSkillId }, { { 'v', parameterFunctionValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HOT,            { { combineFunctionSkillId }, { { 'v', parameterFunctionBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_RECEIVE, { { combineFunctionSkillId }, { { 'v', parameterFunctionOverstackBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_REMOVE,  { { combineFunctionSkillId }, { { 'v', parameterFunctionOverstackValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLOCK,          { { combineFunctionSkillId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::EVADE,          { { combineFunctionSkillId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::INVULNERABLE,   { { combineFunctionSkillId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::MISS,           { { combineFunctionSkillId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'i', parameterFunctionSkillIcon } } } }
		} },
		{ MessageCategory::PLAYER_IN, {
			{ MessageType::PHYSICAL,       { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CRIT,           { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLEEDING,       { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BURNING,        { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::POISON,         { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CONFUSION,      { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::RETALIATION,    { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::TORMENT,        { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::DOT,            { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HEAL,           { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HOT,            { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_RECEIVE, { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionOverstackBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_REMOVE,  { { combineFunctionSkillId, combineFunctionEntityId }, { { 'v', parameterFunctionOverstackValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLOCK,          { { combineFunctionSkillId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::EVADE,          { { combineFunctionSkillId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::INVULNERABLE,   { { combineFunctionSkillId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::MISS,           { { combineFunctionSkillId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } }
		} },
		{ MessageCategory::PET_OUT, {
			{ MessageType::PHYSICAL,       { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CRIT,           { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLEEDING,       { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BURNING,        { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::POISON,         { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CONFUSION,      { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::RETALIATION,    { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::TORMENT,        { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::DOT,            { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HEAL,           { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HOT,            { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_RECEIVE, { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionOverstackBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_REMOVE,  { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'v', parameterFunctionOverstackValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLOCK,          { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::EVADE,          { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::INVULNERABLE,   { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::MISS,           { { combineFunctionSkillId, combineFunctionOtherEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'i', parameterFunctionSkillIcon } } } }
		} },
		{ MessageCategory::PET_IN, {
			{ MessageType::PHYSICAL,       { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CRIT,           { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLEEDING,       { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BURNING,        { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::POISON,         { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::CONFUSION,      { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::RETALIATION,    { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::TORMENT,        { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::DOT,            { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionNegativeBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HEAL,           { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::HOT,            { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_RECEIVE, { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionOverstackBuffValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::SHIELD_REMOVE,  { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'v', parameterFunctionOverstackValue }, { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::BLOCK,          { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::EVADE,          { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::INVULNERABLE,   { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } },
			{ MessageType::MISS,           { { combineFunctionSkillId, combineFunctionOtherEntityId, combineFunctionEntityId }, { { 'n', parameterFunctionEntityName }, { 's', parameterFunctionSkillName }, { 'p', parameterFunctionOtherEntityName}, { 'c', parameterFunctionEntityProfessionColor }, { 'r', parameterFunctionEntityProfessionName }, { 'i', parameterFunctionSkillIcon } } } }
		} }
	};
}

GW2_SCT::MessageData::MessageData(cbtevent * ev, ag * entity, ag * otherEntity, const char * skillname) {
	skillName = (char*)malloc(strlen(skillname) + 1);
	strcpy_s(skillName, strlen(skillname) + 1, skillname);
	value = ev->value;
	buffValue = ev->buff_dmg;
	skillId = ev->skillid;
	if (entity) {
		entityId = entity->id;
		entityProf = entity->prof;
		if (entity->name) {
			entityName = (char*)malloc(strlen(entity->name) + 1);
			strcpy_s(entityName, strlen(entity->name) + 1, entity->name);
		}
	}
	if (otherEntity) {
		otherEntityId = otherEntity->id;
		otherEntityProf = otherEntity->prof;
		if (otherEntity->name) {
			otherEntityName = (char*)malloc(strlen(otherEntity->name) + 1);
			strcpy_s(otherEntityName, strlen(otherEntity->name) + 1, otherEntity->name);
		}
	}
	hasToBeFiltered = Options::getIsSkillFiltered(ev->skillid, skillname);
}

GW2_SCT::MessageData::MessageData(cbtevent1 * ev, ag * entity, ag * otherEntity, const char * skillname) {
	skillName = (char*)malloc(strlen(skillname) + 1);
	strcpy_s(skillName, strlen(skillname) + 1, skillname);
	value = ev->value;
	overstack_value = ev->overstack_value;
	buffValue = ev->buff_dmg;
	skillId = ev->skillid;
	if (entity) {
		entityId = entity->id;
		entityProf = entity->prof;
		if (entity->name) {
			entityName = (char*)malloc(strlen(entity->name) + 1);
			strcpy_s(entityName, strlen(entity->name) + 1, entity->name);
		}
	}
	if (otherEntity) {
		otherEntityId = otherEntity->id;
		otherEntityProf = otherEntity->prof;
		if (otherEntity->name) {
			otherEntityName = (char*)malloc(strlen(otherEntity->name) + 1);
			strcpy_s(otherEntityName, strlen(otherEntity->name) + 1, otherEntity->name);
		}
	}
	hasToBeFiltered = Options::getIsSkillFiltered(ev->skillid, skillname);
}

#ifdef _DEBUG
GW2_SCT::MessageData::MessageData(int32_t value, int32_t buffValue, uint32_t overstack_value, uint32_t skillId, ag* entity, ag* otherEntity, const char* skillname)
	: value(value), buffValue(buffValue), overstack_value(overstack_value), skillId(skillId) {
	skillName = (char*)malloc(strlen(skillname) + 1);
	strcpy_s(skillName, strlen(skillname) + 1, skillname);
	if (entity) {
		entityId = entity->id;
		entityProf = entity->prof;
		if (entity->name) {
			entityName = (char*)malloc(strlen(entity->name) + 1);
			strcpy_s(entityName, strlen(entity->name) + 1, entity->name);
		}
	}
	if (otherEntity) {
		otherEntityId = otherEntity->id;
		otherEntityProf = otherEntity->prof;
		if (otherEntity->name) {
			otherEntityName = (char*)malloc(strlen(otherEntity->name) + 1);
			strcpy_s(otherEntityName, strlen(otherEntity->name) + 1, otherEntity->name);
		}
	}
}
#endif // _DEBUG

GW2_SCT::MessageHandler::MessageHandler(std::vector<std::function<bool(std::vector<std::shared_ptr<MessageData>>, std::vector<std::shared_ptr<MessageData>>)>> tryToCombineWithFunctions, std::map<char, std::function<std::string(std::vector<std::shared_ptr<MessageData>>)>> parameterToStringFunctions)
	: tryToCombineWithFunctions(tryToCombineWithFunctions), parameterToStringFunctions(parameterToStringFunctions) {}

GW2_SCT::EventMessage::EventMessage(MessageCategory category, MessageType type, cbtevent * ev, ag * src, ag * dst, char * skillname)
	: category(category), type(type) {
	switch (category)
	{
	case GW2_SCT::MessageCategory::PLAYER_OUT:
	case GW2_SCT::MessageCategory::PET_OUT:
		messageDatas.push_back(std::make_shared<MessageData>(ev, dst, src, skillname));
		break;
	case GW2_SCT::MessageCategory::PLAYER_IN:
	case GW2_SCT::MessageCategory::PET_IN:
		messageDatas.push_back(std::make_shared<MessageData>(ev, src, dst, skillname));
		break;
	default:
		OutputDebugString("GW2_SCT: Received message for unknown category.");
		break;
	}
}

GW2_SCT::EventMessage::EventMessage(MessageCategory category, MessageType type, cbtevent1 * ev, ag * src, ag * dst, char * skillname)
	: category(category), type(type) {
	switch (category)
	{
	case GW2_SCT::MessageCategory::PLAYER_OUT:
	case GW2_SCT::MessageCategory::PET_OUT:
		messageDatas.push_back(std::make_shared<MessageData>(ev, dst, src, skillname));
		break;
	case GW2_SCT::MessageCategory::PLAYER_IN:
	case GW2_SCT::MessageCategory::PET_IN:
		messageDatas.push_back(std::make_shared<MessageData>(ev, src, dst, skillname));
		break;
	default:
		OutputDebugString("GW2_SCT: Received message for unknown category.");
		break;
	}
}

GW2_SCT::EventMessage::EventMessage(MessageCategory category, MessageType type, std::shared_ptr<MessageData> data)
	: category(category), type(type) {
	messageDatas.push_back(data);
}

std::string GW2_SCT::EventMessage::getStringForOptions(std::shared_ptr<message_receiver_options_struct> opt) {
	if (opt != nullptr) {
		std::string outputTemplate = opt->outputTemplate;
		std::stringstream stm;
		stm << "[col=" << opt->color << "]";
		for (std::string::iterator it = outputTemplate.begin(); it != outputTemplate.end(); ++it) {
			switch (*it) {
			case '%':
				it++;
				if (*it == '%') {
					stm << *it;
				}
				else {
					std::map<MessageCategory, std::map<MessageType, MessageHandler>>::iterator cat = messageHandlers.find(category);
					if (cat != messageHandlers.end()) {
						std::map<MessageType, MessageHandler>::iterator typ = cat->second.find(type);
						if (typ != cat->second.end()) {
							std::map<char, std::function<std::string(std::vector<std::shared_ptr<MessageData>>)>>::iterator parFunction = typ->second.parameterToStringFunctions.find(*it);
							if (parFunction != typ->second.parameterToStringFunctions.end()) {
								stm << parFunction->second(messageDatas);
							}
						}
					}
				}
				break;
			default:
				stm << *it;
				break;
			}
		}
		if (messageDatas.size() > 1) {
			stm << " [[" << messageDatas.size() << " " << langString(GW2_SCT::LanguageCategory::Message, GW2_SCT::LanguageKey::Number_Of_Hits) << "]]";
		}
		stm << "[/col]";

		return stm.str();
	} else {
		return "";
	}
}

std::shared_ptr<GW2_SCT::MessageData> GW2_SCT::EventMessage::getCopyOfFirstData()
{
	if (messageDatas.size() > 0) {
		return std::make_shared<MessageData>(*messageDatas.front());
	}
	return std::shared_ptr<MessageData>();
}

GW2_SCT::MessageCategory GW2_SCT::EventMessage::getCategory() {
	return category;
}

GW2_SCT::MessageType GW2_SCT::EventMessage::getType() {
	return type;
}

bool GW2_SCT::EventMessage::hasToBeFiltered() {
	for (auto m : messageDatas) {
		if (!m->hasToBeFiltered) {
			return false;
		}
	}
	return true;
}

bool GW2_SCT::EventMessage::tryToCombineWith(std::shared_ptr<EventMessage> m) {
	if (m->category == category && m->type == type) {
		std::map<MessageCategory, std::map<MessageType, MessageHandler>>::iterator cat = messageHandlers.find(category);
		if (cat != messageHandlers.end()) {
			std::map<MessageType, MessageHandler>::iterator typ = cat->second.find(type);
			if (typ != cat->second.end()) {
				for (std::vector<std::function<bool(std::vector<std::shared_ptr<MessageData>>, std::vector<std::shared_ptr<MessageData>>)>>::iterator it = typ->second.tryToCombineWithFunctions.begin();
					it != typ->second.tryToCombineWithFunctions.end();
					++it) {
					if (!(*it)(messageDatas, m->messageDatas)) {
						return false;
					}
				}
				for (std::vector<std::shared_ptr<MessageData>>::iterator it = m->messageDatas.begin(); it != m->messageDatas.end(); it++) {
					messageDatas.push_back(*it);
				}
				return true;
			}
		}
	}
	return false;
}
