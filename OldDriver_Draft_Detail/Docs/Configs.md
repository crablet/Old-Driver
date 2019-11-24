# Config/SubjectTwoSettings.json

最外层用一个花括号括起来；第二层是三个选项的英文名，分别是“练习设置”、“配件设置”和“语音设置”；第三层是每个科目二项目的英文名，对应着该项目C++文件的名字；第四层是具体的选项，例如“分数”、“此评测是否生效”等等

```json
{
    "PracticeSettings": {
        "StartingActions": {
            "WeiJiAnQuanDai": {
                "Score": 100,
                "Enable": true
            },
            "WeiFangShouSha": {
                "Score": 100,
                "Enable": true
            },
            "WeiKaiZhuanXiangDeng": {
                "Score": 100,
                "Enable": true
            }
        },
        "ReverseStallParking": {
            "ZhongTuTingChe": {
                "Score": 100,
                "Enable": true
            }

            ...
        }

        ...
    }
}
```
