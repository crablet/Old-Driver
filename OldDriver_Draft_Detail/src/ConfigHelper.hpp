#ifndef CONFIGHELPER_HPP
#define CONFIGHELPER_HPP

#include <type_traits>
#include <filesystem>
#include <fstream>

#include <QIODevice>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class SettingPageBase;	// 前置声明，为了编译通过

template <auto>
struct AlwaysFalseHelper : public std::false_type
{
};

// 无论传入什么参数都会转化为false，用于实现static_assert(false, "xxx")而不编译错误
template <auto T>
inline auto constexpr AlwaysFalse = AlwaysFalseHelper<T>::value;

namespace Subject
{
	namespace Two	// 科目二
	{
		// 科目二的小项目的枚举量
		enum class PracticeSettings : short
		{
			StartingActions,		// 起步动作
			ReverseStallParking,	// 倒车入库
			SideParking,			// 侧方停车
			RampFixedPoint,			// 坡道定点
			RightAngleTurn,			// 直角转弯
			CurveDriving,			// 曲线行驶
			NarrowRoadTurnAround,	// 窄路掉头
			ParkAndTakeTheCard,		// 停车取卡
			EmergencyTreatment,		// 紧急处置
			TunnelDriving			// 隧道行驶
		};

		inline constexpr short DeviceSettings = 1121;
	}
}

class Config
{
public:
	// 功能同于将Subject::Two::PracticeSettings::StartingActions转换为QString("StartingActions")
	template <Subject::Two::PracticeSettings Type>
	static QString PageNameOf() noexcept
	{
		using STP = Subject::Two::PracticeSettings;
		if constexpr (Type == STP::StartingActions)
		{
			return "StartingActions";
		}
		else if constexpr (Type == STP::ReverseStallParking)
		{
			return "ReverseStallParking";
		}
		else if constexpr (Type == STP::SideParking)
		{
			return "SideParking";
		}
		else if constexpr (Type == STP::RampFixedPoint)
		{
			return "RampFixedPoint";
		}
		else if constexpr (Type == STP::RightAngleTurn)
		{
			return "RightAngleTurn";
		}
		else if constexpr (Type == STP::CurveDriving)
		{
			return "CurveDriving";
		}
		else if constexpr (Type == STP::NarrowRoadTurnAround)
		{
			return "NarrowRoadTurnAround";
		}
		else if constexpr (Type == STP::ParkAndTakeTheCard)
		{
			return "ParkAndTakeTheCard";
		}
		else if constexpr (Type == STP::EmergencyTreatment)
		{
			return "EmergencyTreatment";
		}
		else if constexpr (Type == STP::TunnelDriving)
		{
			return "TunnelDriving";
		}
		else
		{
			static_assert(AlwaysFalse<Type>, "给PageNameOf传入的项目名字不对");

			return "WrongCall";
		}
	}

	// 功能同返回Subject::Two::PracticeSettings::StartingActions的评分细则的列表
	template <Subject::Two::PracticeSettings Type>
	static std::vector<QString> ItemsNameOf() noexcept
	{
		using STP = Subject::Two::PracticeSettings;
		if constexpr (Type == STP::StartingActions)
		{
			return { "WeiJiAnQuanDai", "WeiFangShouSha", "WeiKaiZhuanXiangDeng" };
		}
		else if constexpr (Type == STP::ReverseStallParking)
		{
			return { "ZhongTuTingChe", "CheShenChuXian", "DaoKuBuRu",
					 "BuAnGuiDingLuXianXingShi", "TingCheQianLiangQianLunWeiGuoKuQuKongZhiXian",
					 "QuanChengXianShi210S" };
		}
		else if constexpr (Type == STP::SideParking)
		{
			return { "XingShiZhongCheLunChuYaCheDaoBianYuanXian", "XingShiZhongCheLunChuPengKuQuBianXian",
					 "CheLiangRuKuTingZhiHouCheShenChuXian", "ZhongTuTingChe", "QuanChengXianShi90S" };
		}
		else if constexpr (Type == STP::RampFixedPoint)
		{
			return	{ "CheLiangTingZhiHouCheShenJuLiLuBianYuanXianChaoGuo30cmDanWeiChaoGuo50cm",
					  "CheLiangTingZhiHouCheShenJuLiLuBianYuanXianChaoGuo50cm",
					  "TingCheHouWeiLaJinZhuCheZhiDongQi",
					  "CheLiangTingZhiHouCheQianBaoXianGangWeiDaoTingCheXianQianHouChaoChu50cm",
					  "CheLiangTingZhiHouCheQianBaoXianGangWeiDaoTingCheXianQianHouWeiChaoChu50cm",
					  "CheLiangHouLiuDaYu30cm", "CheLiangHouLiuXiaoYu30cm",
					  "CheLiangTingZhiHouQiBuShiJianGuiDing15s" };
		}
		else if constexpr (Type == STP::RightAngleTurn)
		{
			return { "ZhuanWanQianBuShiYongHuoCuoWuShiYongZhuanXiangDeng",
					  "ZhuanWanHouBuGuanBiZhuanXiangDeng", "ZhongTuTingChe",
					  "CheLunChuYaDaoLuBianYuanXian" };
		}
		else if constexpr (Type == STP::CurveDriving)
		{
			return { "XingShiShiDangWeiWeiGuaiZaiErDangJiYiShang", "ZhongTuTingChe15s",
					  "CheLunYaDaoLuBianYuanXian" };
		}
		else if constexpr (Type == STP::NarrowRoadTurnAround)
		{
			return { "CheLunYaBianYuanXian", "SanJinErTuiWeiWanChengDiaoTou", "XiangMuWanChengShiJian" };
		}
		else if constexpr (Type == STP::ParkAndTakeTheCard)
		{
			return { "TingCheHouWeiGuaKongDang", "TingCheHouWeiLaJinZhuCheZhiDongQi",
					 "TingCheHouCheShenJuDaoLuBianYuanXianDaYu50cm",
					 "TingCheHouDaoCheJiaoZhengWeiZhi", "CheLunChuYaDaoLuBianYuanXian",
					 "ShiGuoTingCheQuKaWeiZhiWeiTingChe" };
		}
		else if constexpr (Type == STP::EmergencyTreatment)
		{
			return { "TingCheHouWeiKaiQiWeiXianBaoJingShanGuangDeng", "WeiJiShiZhiDong" };
		}
		else if constexpr (Type == STP::TunnelDriving)
		{
			return { "CheSuFanWei510kmh", "ShiRuSuiDaoShiWeiJianSu",
					 "ShiRuSuiDaoShiWeiKaiQiQianZhaoDeng",
					 "ShiRuSuiDaoHouBuAnGuiDingCheDaoXingShiBianDao",
					 "ShiRuSuiDaoShiChuRuKouShiWeiMingLaBa",
					 "ShiChuSuiDaoHouWeiGuanBiQianZhaoDeng", "ZhongTuTingChe" };
		}
		else
		{
			static_assert(AlwaysFalse<Type>, "给ItemsName传入的项目名字不对");

			return { "Wrong", "Call" };
		}
	}

	// 返回项目的中文名对应的英文名
	static QString ItemNameOf(const QString &Item) noexcept
	{
		if (Item == "指纹仪")
		{
			return "FingerprintInstrucment";
		}
		else if (Item == "身份识别器")
		{
			return "IdentityCard";
		}
		else if (Item == "人脸识别摄像头")
		{
			return "FaceRecognitionCamera";
		}
		else
		{
			// 程序出现错误，这里应该有一些处理措施，待写
			return "";
		}
	}

	// 该函数用于保存设置，针对科目二的小项目
	// 返回值：true->保存成功，false->保存失败
	template <Subject::Two::PracticeSettings Type>
	static bool Save(SettingPageBase *Workload)
	{
		QFile JsonFile(JsonFilePath);
		if (!JsonFile.open(QIODevice::ReadOnly))
		{
			return false;	// 配置文件打开失败，直接返回
		}

		auto TopJsonDocument = QJsonDocument::fromJson(JsonFile.readAll()).object();	// 为了保存文件方便，这个中间变量也留着
		auto JsonDocument = TopJsonDocument["PracticeSettings"].toObject();	// 取出了"PracticeSettings"这个对象，子对象有各个具体项目的设置，见文档./Docs/Configs.md

		auto &Labels = Workload->GetLabels();		// 存放项目名称
		auto &Comboxs = Workload->GetComboxs();		// 存放项目分数
		auto &CheckBoxs = Workload->GetCheckBoxs();	// 存放是否启用该项目

		// 要确保三者的大小是一样的，因为后面强烈依赖这一先决条件
		if (!(Labels.size() == Comboxs.size() && Comboxs.size() == CheckBoxs.size()))
		{
			return false;
		}

		const auto Names = ItemsNameOf<Type>();	// 每个小项目的名字集合，为了运行时进行不必要的中英文对应转换从而降低性能，这里硬编码下来，但要求顺序严格一一对应
		const auto PageName = PageNameOf<Type>();	// 现在所处的页面的名字

		auto ThisItemJson = JsonDocument[PageName].toObject();
		for (int i = 0; i < static_cast<int>(Labels.size()); ++i)
		{
			auto Now = ThisItemJson[Names[i]].toObject();
			Now["Score"] = Comboxs[i]->currentText().toInt();
			Now["Enable"] = CheckBoxs[i]->isChecked();

			ThisItemJson.insert(Names[i], Now);
		}

		JsonDocument.insert(PageName, ThisItemJson);	// 写入与"StartingActions"同级的Key为PageName的修改
		TopJsonDocument.insert("PracticeSettings", JsonDocument);	// 写入整个"PracticeSettings"的修改

		JsonFile.close();	// 先关闭
		JsonFile.open(QIODevice::WriteOnly);	// 再打开，因为一开始就这个模式的话会把之前的数据清空
		JsonFile.write(QJsonDocument(TopJsonDocument).toJson());
		JsonFile.close();

		return true;
	}

	template <short Type>
	static bool Save(SettingPageBase *Workload)
	{
		if constexpr (Type == Subject::Two::DeviceSettings)
		{
			QFile JsonFile(JsonFilePath);
			if (!JsonFile.open(QIODevice::ReadOnly))
			{
				return false;	// 配置文件打开失败，直接返回
			}

			auto TopJsonDocument = QJsonDocument::fromJson(JsonFile.readAll()).object();	// 为了保存文件方便，这个中间变量也留着
			auto JsonDocument = TopJsonDocument["DeviceSettings"].toObject();	// 取出了"DeviceSettings"这个对象，子对象有各个具体项目的设置，见文档./Docs/Configs.md

			auto &Labels = Workload->GetLabels();		// 存放项目名称
			auto &CheckBoxs = Workload->GetCheckBoxs();	// 存放是否启用该项目

			// 要确保两者的大小是一样的，因为后面强烈依赖这一先决条件
			if (Labels.size() != CheckBoxs.size())
			{
				return false;
			}

			for (std::size_t i = 0; i < Labels.size(); ++i)
			{
				const auto Name = ItemNameOf(Labels[i]->text());
				auto TempJson = JsonDocument[Name].toObject();
				TempJson["Enable"] = CheckBoxs[i]->isChecked();

				JsonDocument.insert(Name, TempJson);
			}
			TopJsonDocument.insert("DeviceSettings", JsonDocument);

			JsonFile.close();	// 先关闭
			JsonFile.open(QIODevice::WriteOnly);	// 再打开，因为一开始就这个模式的话会把之前的数据清空
			JsonFile.write(QJsonDocument(TopJsonDocument).toJson());
			JsonFile.close();

			return true;
		}
		else
		{
			static_assert(AlwaysFalse<Type>, "给Save传入的页面名字不对");

			return false;
		}
	}

	// 从Json文件中加载配置
	template <Subject::Two::PracticeSettings Type>
	static bool Load(SettingPageBase *Workload)
	{
		QFile JsonFile(JsonFilePath);
		if (!JsonFile.open(QIODevice::ReadOnly))
		{
			return false;	// 配置文件打开失败，直接返回
		}

		auto TopJsonDocument = QJsonDocument::fromJson(JsonFile.readAll()).object();	// 为了保存文件方便，这个中间变量也留着
		auto JsonDocument = TopJsonDocument["PracticeSettings"].toObject();	// 取出了"PracticeSettings"这个对象，子对象有各个具体项目的设置，见文档./Docs/Configs.md

		JsonFile.close();	// 及时关闭文件，以防忘记

		auto &Labels = Workload->GetLabels();		// 存放项目名称
		auto &Comboxs = Workload->GetComboxs();		// 存放项目分数
		auto &CheckBoxs = Workload->GetCheckBoxs();	// 存放是否启用该项目

		// 要确保三者的大小是一样的，因为后面强烈依赖这一先决条件
		if (!(Labels.size() == Comboxs.size() && Comboxs.size() == CheckBoxs.size()))
		{
			return false;
		}

		const auto Names = ItemsNameOf<Type>();	// 每个小项目的名字集合，为了运行时进行不必要的中英文对应转换从而降低性能，这里硬编码下来，但要求顺序严格一一对应
		const auto PageName = PageNameOf<Type>();	// 现在所处的页面的名字

		// 包含当前项目所有扣分点的设置的Json
		auto ThisItemJson = JsonDocument[PageName].toObject();
		for (int i = 0; i < static_cast<int>(Labels.size()); ++i)
		{
			auto Now = ThisItemJson[Names[i]].toObject();
			Comboxs[i]->setCurrentIndex(
										Comboxs[i]->findText(
															 QString::number(
																			 Now["Score"].toInt())));	// 根据Json设置该扣分点的分数
			CheckBoxs[i]->setChecked(Now["Enable"].toBool());		// 根据Json设置该扣分点是否生效
		}

		return true;
	}

	// 从Json文件中加载配置
	template <short Type>
	static bool Load(SettingPageBase *Workload)
	{
		if constexpr (Type == Subject::Two::DeviceSettings)
		{
			QFile JsonFile(JsonFilePath);
			if (!JsonFile.open(QIODevice::ReadOnly))
			{
				return false;	// 配置文件打开失败，直接返回
			}

			auto TopJsonDocument = QJsonDocument::fromJson(JsonFile.readAll()).object();	// 为了保存文件方便，这个中间变量也留着
			auto JsonDocument = TopJsonDocument["DeviceSettings"].toObject();	// 取出了"DeviceSettings"这个对象，子对象有各个具体项目的设置，见文档./Docs/Configs.md

			JsonFile.close();	// 及时关闭文件，以防忘记

			auto &Labels = Workload->GetLabels();		// 存放项目名称
			auto &CheckBoxs = Workload->GetCheckBoxs();	// 存放是否启用该项目

			// 要确保三者的大小是一样的，因为后面强烈依赖这一先决条件
			if (Labels.size() != CheckBoxs.size())
			{
				return false;
			}

			for (std::size_t i = 0; i < Labels.size(); ++i)
			{
				auto TempJson = JsonDocument[ItemNameOf(Labels[i]->text())].toObject();
				CheckBoxs[i]->setChecked(TempJson["Enable"].toBool());
			}

			return true;
		}
		else
		{
			static_assert(AlwaysFalse<Type>, "给Load传入的页面名称不对");

			return false;
		}
	}

	static void CreateInitialConfigFile()
	{
		namespace fs = std::filesystem;
		if (!fs::exists(JsonFileDirectory))	// 若Config目录不存在则创建
		{
			fs::create_directory(JsonFileDirectory);
		}
		if (!fs::exists(JsonFilePath))	// 若Config/SubjectTwo.json文件不存在则创建
		{
			std::ofstream(JsonFilePath);	// 创建文件（不得不说这个技巧真是扭曲）
		}

		auto RawJson = 
R"({
    "PracticeSettings": {
        "ReverseStallParking": {
            "BuAnGuiDingLuXianXingShi": {
                "Enable": true,
                "Score": 100
            },
            "CheShenChuXian": {
                "Enable": true,
                "Score": 100
            },
            "ChenShenChuXian": {
                "Enable": true,
                "Score": 100
            },
            "DaoKuBuRu": {
                "Enable": true,
                "Score": 100
            },
            "QuanChengXianShi210S": {
                "Enable": true,
                "Score": 100
            },
            "TingCheQianLiangQianLunWeiGuoKuQuKongZhiXian": {
                "Enable": true,
                "Score": 100
            },
            "ZhongTuTingChe": {
                "Enable": true,
                "Score": 100
            }
        },
        "StartingActions": {
            "WeiFangShouSha": {
                "Enable": true,
                "Score": 100
            },
            "WeiJiAnQuanDai": {
                "Enable": true,
                "Score": 100
            },
            "WeiKaiZhuanXiangDeng": {
                "Enable": true,
                "Score": 100
            }
        },
        "SideParking": {
            "XingShiZhongCheLunChuYaCheDaoBianYuanXian": {
                "Enable": true,
                "Score": 100
            },
            "XingShiZhongCheLunChuPengKuQuBianXian": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangRuKuTingZhiHouCheShenChuXian": {
                "Enable": true,
                "Score": 100
            },
            "ZhongTuTingChe": {
                "Enable": true,
                "Score": 100
            },
            "QuanChengXianShi90S": {
                "Enable": true,
                "Score": 100
            }
        },
        "RampFixedPoint": {
            "CheLiangTingZhiHouCheShenJuLiLuBianYuanXianChaoGuo30cmDanWeiChaoGuo50cm": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangTingZhiHouCheShenJuLiLuBianYuanXianChaoGuo50cm": {
                "Enable": true,
                "Score": 100
            },
            "TingCheHouWeiLaJinZhuCheZhiDongQi": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangTingZhiHouCheQianBaoXianGangWeiDaoTingCheXianQianHouChaoChu50cm": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangTingZhiHouCheQianBaoXianGangWeiDaoTingCheXianQianHouWeiChaoChu50cm": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangHouLiuDaYu30cm": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangHouLiuXiaoYu30cm": {
                "Enable": true,
                "Score": 100
            },
            "CheLiangTingZhiHouQiBuShiJianGuiDing15s": {
                "Enable": true,
                "Score": 100
            }
        },
        "RightAngleTurn": {
            "ZhuanWanQianBuShiYongHuoCuoWuShiYongZhuanXiangDeng": {
                "Enable": true,
                "Score": 100
            },
            "ZhuanWanHouBuGuanBiZhuanXiangDeng": {
                "Enable": true,
                "Score": 100
            },
            "ZhongTuTingChe": {
                "Enable": true,
                "Score": 100
            },
            "CheLunChuYaDaoLuBianYuanXian": {
                "Enable": true,
                "Score": 100
            }
        },
        "CurveDriving": {
            "XingShiShiDangWeiWeiGuaiZaiErDangJiYiShang": {
                "Enable": true,
                "Score": 100
            },
            "ZhongTuTingChe15s": {
                "Enable": true,
                "Score": 100
            },
            "CheLunYaDaoLuBianYuanXian": {
                "Enable": true,
                "Score": 100
            }
        },
        "NarrowRoadTurnAround": {
            "CheLunYaBianYuanXian": {
                "Enable": true,
                "Score": 100
            },
            "SanJinErTuiWeiWanChengDiaoTou": {
                "Enable": true,
                "Score": 100
            },
            "XiangMuWanChengShiJian": {
                "Enable": true,
                "Score": 100
            }
        },
        "ParkAndTakeTheCard": {
            "TingCheHouWeiGuaKongDang": {
                "Enable": true,
                "Score":100
            },
            "TingCheHouWeiLaJinZhuCheZhiDongQi": {
                "Enable": true,
                "Score":100
            },
            "TingCheHouCheShenJuDaoLuBianYuanXianDaYu50cm": {
                "Enable": true,
                "Score":100
            },
            "TingCheHouDaoCheJiaoZhengWeiZhi": {
                "Enable": true,
                "Score":100
            },
            "CheLunChuYaDaoLuBianYuanXian": {
                "Enable": true,
                "Score":100
            },
            "ShiGuoTingCheQuKaWeiZhiWeiTingChe": {
                "Enable": true,
                "Score":100
            }
        },
        "EmergencyTreatment": {
            "TingCheHouWeiKaiQiWeiXianBaoJingShanGuangDeng": {
                "Enable": true,
                "Score": 100
            },
            "WeiJiShiZhiDong": {
                "Enable": true,
                "Score": 100
            }
        },
        "TunnelDriving": {
            "CheSuFanWei510kmh": {
                "Enable": true,
                "Score": 100
            },
            "ShiRuSuiDaoShiWeiJianSu": {
                "Enable": true,
                "Score": 100
            },
            "ShiRuSuiDaoShiWeiKaiQiQianZhaoDeng": {
                "Enable": true,
                "Score": 100
            },
            "ShiRuSuiDaoHouBuAnGuiDingCheDaoXingShiBianDao": {
                "Enable": true,
                "Score": 100
            },
            "ShiRuSuiDaoShiChuRuKouShiWeiMingLaBa": {
                "Enable": true,
                "Score": 100
            },
            "ShiChuSuiDaoHouWeiGuanBiQianZhaoDeng": {
                "Enable": true,
                "Score": 100
            },
            "ZhongTuTingChe": {
                "Enable": true,
                "Score": 100
            }
        }
    },
    "DeviceSettings": {
        "FingerprintInstrucment": {
            "Enable": true
        },
        "IdentityCard": {
            "Enable": true
        },
        "FaceRecognitionCamera": {
            "Enable": true
        }
    }
})";

		std::ofstream File(JsonFilePath, std::ios::binary | std::ios::trunc);
		File << RawJson;	// 往配置文件中写入初始值
	}

	// 指示该程序是否是第一次运行，如果不是第一次运行，则在程序运行目录下生成“First Run”文件
	static bool IsFirstRun() noexcept
	{
		namespace fs = std::filesystem;
		static bool Exists = fs::exists("First Run");
		if (Exists)
		{
			return false;
		}
		else
		{
			std::ofstream("First Run");	// 建立“First Run”文件
			Exists = true;

			return true;
		}
	}

private:
	static constexpr const char *JsonFilePath = "Config/SubjectTwo.json";
	static constexpr const char *JsonFileDirectory = "Config";
};

#endif // CONFIGHELPER_HPP
