//namd.c
#include <ansi.h>

mapping surname=([
"ÕÔ"    :  "zhao",         "Ç®"    :  "qian",         
"Ëï"    :  "sun",          "Àî"    :  "li",           
"ÖÜ"    :  "zhou",         "Îâ"    :  "wu",           
"Ö£"    :  "zhen",         "Íõ"    :  "wang",         
"·ë"    :  "feng",         "³Â"    :  "chen",         
"ñÒ"    :  "zhu",          "ÎÀ"    :  "wei",          
"½¯"    :  "jiang",        "Éò"    :  "shen",         
"º«"    :  "han",          "Ñî"    :  "yang",         
"Öì"    :  "zhu",          "ÇØ"    :  "qin",         
"ÓÈ"    :  "you",          "Ðí"    :  "xu",           
"ºÎ"    :  "he",           "ÂÀ"    :  "lu",           
"Ê©"    :  "shi",          "ÕÅ"    :  "zhang",        
"¿×"    :  "kong",         "²Ü"    :  "cao",          
"ÑÏ"    :  "yan",          "»ª"    :  "hua",          
"½ð"    :  "jin",          "Îº"    :  "wei",          
"ÌÕ"    :  "tao",          "½ª"    :  "jiang",        
"ÆÝ"    :  "qie",          "Ð»"    :  "xie",          
"×Þ"    :  "zhou",         "Ó÷"    :  "yu",           
"°Ø"    :  "bo",           "Ë®"    :  "shui",         
"ñ¼"    :  "dou",          "ÕÂ"    :  "zhang",        
"ÔÆ"    :  "yun",          "ËÕ"    :  "su",           
"ÅË"    :  "pan",          "¸ð"    :  "ge",           
"ÞÉ"    :  "xi",           "·¶"    :  "fan",          
"Åí"    :  "peng",         "ÀÉ"    :  "lang",         
"Â³"    :  "lu",           "Î¤"    :  "wei",          
"²ý"    :  "chang",        "Âí"    :  "ma",           
"Ãç"    :  "miao",         "·ï"    :  "feng",         
"»¨"    :  "hua",          "·½"    :  "fang",         
"Éµ"    :  "sha",          "ÈÎ"    :  "ren",          
"Ô¬"    :  "yuan",         "Áø"    :  "liu",          
"µË"    :  "deng",         "±«"    :  "bao",          
"Ê·"    :  "shi",          "ÌÆ"    :  "tang",         
"·Ñ"    :  "fei",          "Á®"    :  "lian",         
"á¯"    :  "chen",         "Ñ¦"    :  "xue",          
"À×"    :  "lei",          "ºØ"    :  "he",           
"Äß"    :  "ni",           "ÌÀ"    :  "tang",         
"ÌÙ"    :  "teng",         "Òó"    :  "yin",          
"ÂÞ"    :  "luo",          "»ª"    :  "hua",          
"ºÂ"    :  "hao",          "Úù"    :  "wu",           
"°²"    :  "an",           "³£"    :  "chang",        
"ÀÖ"    :  "le",           "´ô"    :  "dai",          
"Ê±"    :  "shi",          "¸¶"    :  "fu",           
"Æ¤"    :  "pi",           "±å"    :  "bian",         
"Æë"    :  "qi",           "¿µ"    :  "kang",         
"Îé"    :  "wu",           "Óà"    :  "yu",           
"Ôª"    :  "yuan",         "²·"    :  "po",           
"¹Ë"    :  "gu",           "Ó¯"    :  "ying",         
"Æ½"    :  "ping",         "»Æ"    :  "huang",        
"ºÍ"    :  "he",           "ÄÂ"    :  "mu",           
"Ð¤"    :  "xiao",         "Òü"    :  "yin",          
"Ò¦"    :  "yao",          "ÉÛ"    :  "shao",         
"Õ¿"    :  "zhan",         "Íô"    :  "wang",         
"Æî"    :  "qi",           "Ã«"    :  "mao",          
"Óí"    :  "yu",           "µÒ"    :  "di",           
"Ã×"    :  "mi",           "±´"    :  "bei",          
"Ã÷"    :  "ming",         "²Ø"    :  "zang",         
"¼Æ"    :  "ji",           "·ü"    :  "fu",           
"³É"    :  "cheng",        "´÷"    :  "dai",          
"Ì¸"    :  "tan",          "ËÎ"    :  "song",         
"Ã©"    :  "mao",          "ÅÓ"    :  "pang",         
"ÐÜ"    :  "xiong",        "¼Í"    :  "ji",           
"Êæ"    :  "su",           "Çü"    :  "qu",           
"Ïî"    :  "xiang",        "×£"    :  "zhu",          
"¶­"    :  "dong",         "Áº"    :  "liang",        
"·®"    :  "fan",          "ºú"    :  "hu",           
"Áè"    :  "ling",         "»ô"    :  "ho",           
"ÓÝ"    :  "yu",           "Íò"    :  "wan",          
"Ö§"    :  "zhi",          "¿Â"    :  "ke",           
"êÃ"    :  "jiu",          "¹Ü"    :  "guan",         
"Â¬"    :  "lu",           "Ó¢"    :  "ying",         
"³ð"    :  "qiu",          "ºò"    :  "hou",          
"ÔÀ"    :  "yue",          "Ë§"    :  "suai",         
"Ë¾Âí"  :  "sima",         "ÉÏ¹Ù"  :  "shangguan",    
"Å·Ñô"  :  "ouyang",       "ÏÄºò"  :  "xiahou",       
"Öî¸ð"  :  "zhuge",        "ÎÅÈË"  :  "wenren",       
"¶«·½"  :  "dongfang",     "ºÕÁ¬"  :  "helian",       
"»Ê¸¦"  :  "huangpu",      "Î¾³Ù"  :  "yuchi",       
"¹«Ñò"  :  "gongyang",     "å£Ì¨"  :  "zhantai",      
"¹«ÖÎ"  :  "gongye",       "×ÚÕþ"  :  "zongzheng",    
"å§Ñô"  :  "puyang",       "´¾ÓÚ"  :  "chunyu",       
"µ¥ÓÚ"  :  "shanyu",       "ß³Ç¬"  :  "chigan",       
"ÉêÍÀ"  :  "shentu",       "¹«Ëï"  :  "gongsun",     
"ÖÙËï"  :  "zhongsun",     "Ô¯Ðù"  :  "xuanyuan",     
"Áîºü"  :  "linghu",       "ÖÓÀë"  :  "zhongli",      
"ÓîÎÄ"  :  "yuwen",        "³¤Ëï"  :  "zhangsun",    
"Ä»ÈÝ"  :  "murong",       "Ë¾Í½"  :  "situ",         
"Ê¦¿Õ"  :  "shikong",      "ò§¿×"  :  "zhuankong",    
"¶ËÄ¾"  :  "duanmu",       "Î×Âí"  :  "wuma",         
"¹«Î÷"  :  "gongxi",       "Æáµñ"  :  "qidiao",       
"ÀÖÕý"  :  "lezheng",      "ÈÀæá"  :  "xiangsi",      
"¹«Á¼"  :  "gongliang",    "ÍØÖº"  :  "tuozhi",       
"¼Ð¹È"  :  "jiagu",        "Ô×¸¸"  :  "zaifu",        
"¹ÈÁº"  :  "guliang",      "³þ½ú"  :  "chujing",      
"¶À¹Â"  :  "dugu",        "ÈêÛ³"  :  "ruye",         
"Í¿ÇÕ"  :  "tuqin",        "¶ÎÇ§"  :  "duanqian",     
"°ÙÀï"  :  "baili",        "¶«¹ù"  :  "dongguo",      
"ÄÏ¹ù"  :  "nanguo",       "ºôÑÓ"  :  "huyan",        
"¹éº£"  :  "guihai",       "ÑòÉà"  :  "yangshe",      
"Î¢Éú"  :  "weisheng",     "ÁºÇð"  :  "liangqiu",     
"×óÇð"  :  "zuoqiu",       "¶«ÃÅ"  :  "dongmen",      
"Î÷ÃÅ"  :  "ximen",        "°ÛÉÍ"  :  "baishang",     
"ÄÏ¹Ù"  :  "nangong",      "çÃ"    :  "gou",          
"¿º"    :  "kang",         "¿ö"    :  "kuang",        
"ºó"    :  "hou",          "ÓÐ"    :  "you",          
"ÇÙ"    :  "qing",         "ÉÌ"    :  "shang",        
"Ä²"    :  "mo",           "ÙÜ"    :  "she",          
"¶ú"    :  "er",           "Ä«"    :  "mo",           
"¹þ"    :  "ha",           "ÚÛ"    :  "qiao",         
"Äê"    :  "nian",         "°®"    :  "ai",           
"Ñô"    :  "yang",         "Ù¡"    :  "dong",         
"µÚ"    :  "di",           "Îå"    :  "wu",           
"ÑÔ"    :  "yan",          "¸£"    :  "fu",           
"Øá"    :  "kai",          "ÖÓ"    :  "zong",         
"×Ú"    :  "zong",         "ÁÖ"    :  "lin",          
"Ê¯"    :  "shi",
]);

mapping jp_surname=([
"É½±¾"  :  "shanben",      "¹êÌï"  :  "guitian",      
"×ËÈý"  :  "zisan",        "´óµº"  :  "dadao",        
"ËÉÏÂ"  :  "songxia",      "ºáÌï"  :  "hengtian",     
"¶«Ö¥"  :  "dongzhi",      "ºò±¾"  :  "houben",       
"´¨Ò°"  :  "chuangye",     "É½¿Ú"  :  "shankou",      
"ÁåÄ¾"  :  "lingmu",       "¸Ú²Ö"  :  "gangcang",     
"Ð¡µº"  :  "xiaodao",      "¾®ÉÏ"  :  "jinshang",     
"°²ÄÎ"  :  "annai",        "Ç³Ìï"  :  "qiantian",     
"×ôÌÙ"  :  "zuoteng",      "¹ãÄ©"  :  "guangmu",      
"´óÖñ"  :  "dazhu",        "´ó´å"  :  "dachun",       
"²®×ô"  :  "bozuo",        "¸»¸Ô"  :  "fugang",       
"¶«Ïç"  :  "dongxiang",
]);

mapping middle_name=([
"ÖÒ" : "zhong",		"Ð¢" : "xiao",
"Àñ" : "li",		"Òå" : "yi",
"ÖÇ" : "zhi",		"²»" : "bu",
"ÈÊ" : "ren",		"¿ï" : "kuang",
"ÏÜ" : "xian",		"Áî" : "ling",
"¸£" : "fu",		"ÄÎ" : "nai",
"´ó" : "da",		"Ð¡" : "xiao",
"Ïþ" : "xiao",		"¸ß" : "gao",
"¿É" : "ke",		"°¢" : "a",
"½ð" : "jin",		"ÊÀ" : "shi",
"¿Ë" : "ke",		"Êå" : "shu",
"Ö®" : "zhi",		"·Ç" : "fei",
"·ò" : "fu",		"Ê±" : "shi",
"Èô" : "ruo",		"Çì" : "qing",
"ÎÄ" : "wen",		"Îä" : "wu",
"¶à" : "duo",		"²Å" : "cai",
"³¤" : "zhang",		"×Ó" : "zi",
"ÓÀ" : "yong",		"ÓÑ" : "you",
"¾Å" : "jiu",		"ÈË" : "ren",
"Îª" : "weo",		"Ò»" : "yi",
]);

mapping male_name=([
"°Ô" : "ba",		"°×" : "bai",
"°à" : "ban",		"±ó" : "bin",
"±ö" : "bin",		"²ý" : "chang",
"³¬" : "chao",		"³Ï" : "cheng",
"´¨" : "chuan",		"¶¦" : "ding",
"¶¨" : "ding",		"·¨" : "fa",
"·É" : "fei",		"·ç" : "feng",
"·æ" : "feng",		"¸Ö" : "gan",
"î¸" : "gan",		"¹á" : "gui",
"¹â" : "guang",		"º£" : "hai",
"»¢" : "hu",		"»ª" : "hua",
"ºÆ" : "hao",		"ºê" : "hong",
"¼Ã" : "ji",		"¼á" : "jian",
"½¡" : "jian",		"½£" : "jian",
"½­" : "jiang",		"½ø" : "jin",
"½Ü" : "jie",		"¿¡" : "jun",
"¿µ" : "kan",		"Á¼" : "liang",
"÷ë" : "qi",		"Ãñ" : "min",
"Ã÷" : "ming",		"Ãù" : "ming",
"Äþ" : "ning",		"Åà" : "pei",
"Æô" : "qi",		"Ç¿" : "qiang",
"ÈÙ" : "rong",		"É½" : "shan",
"Ì©" : "tai",		"ÌÎ" : "tao",
"Í¦" : "ting",		"Î°" : "wei",
"Îõ" : "xi",		"Ïé" : "xiang",
"ÐÛ" : "xiong",		"Ðñ" : "xu",
"¶·" : "dou",		"Òã" : "yi",
"è¤" : "yu",		"Óð" : "yu",
"Óî" : "yu",		"ÔÀ" : "yue",
"ÖÛ" : "zhou",		
]);
			
mapping female_name=([
"°®" : "ai",		"´º" : "chun",
"µ¤" : "dan",		"·¼" : "fang",
"·Ò" : "fen",		"·ï" : "feng",
"¹Ã" : "gu",		"ºì" : "hong",
"ºç" : "hong",		"½¿" : "jiao",
"¾ê" : "juan",		"¾Õ" : "ju",
"À¼" : "lan",		"á°" : "lan",
"Àö" : "li",		"Àò" : "li",
"Á«" : "lian",		"Áá" : "ling",
"ÁÕ" : "lin",		"ÄÈ" : "na",
"ÇÙ" : "qin",		"ÇÛ" : "qin",
"Ù»" : "qian",		"Æ¼" : "ping",
"æÃ" : "ding",		"Ï¼" : "xia",
"Ïã" : "xiang",		"¶ù" : "er",
"Ñà" : "yan",		"Ó¢" : "ying",
"çø" : "ying",		"Óñ" : "yu",
"Õä" : "zhen",		"Öé" : "zhu",
]);
	
mapping jp_name=([
"Ì«ÀÉ"   : "tailang",		"´ÎÀÉ"   : "cilang",
"ÈýÀÉ"   : "sanlang",		"ËÄÀÉ"   : "silang",
"ÎåÀÉ"   : "wulang",		"Ê®Ò»ÀÉ" : "shiyilang",
"Ê®ËÄÀÉ" : "shisilang",		"¶þÊ®Áù" : "ershiliu",
"¿¡Ê÷"   : "junshu",		"Äþ´Î"   : "ningci",
"Ó¢»ú"   : "yingji",		"Ò±×Ö"   : "zhizi",
"¿¡ÐÛ"   : "junxiong",		"ÄÁ·ò"   : "mufu",
"¹â·ò"   : "guangfu",		"¾´Ò»"   : "jingyi",
"Ó¢ÊÀ"   : "yingshi",		"ÊþÊ¯"   : "shushi",
"Óå¼ª"   : "yuji",		"Ò»Ò¶"   : "yiye",
"×Ó¹æ"   : "zigui",		"µ¾Ôì"   : "daozhao",
"ÒÁ³å"   : "yichong",		"ËÉÔ°"   : "songyuan",
"ÉîË®"   : "shenshui",		"´ó¹Û"   : "daguan",
"·á¹ú"   : "fengguo",		"Ð¢ºÍ"   : "xiaohe",
"Ã¯"     : "mao",		"´¨"     : "chuan",
"ÎÀ"     : "wei",		"µºÊÙ"   : "daoshou",
"¹âÔÆ"   : "guangyun",		"°²ÖÎ"   : "anzhi",
"É½ÀÖ"   : "shanle",		"ÃÎ¶þ"   : "menger",
]);

mapping color_list = ([
"³à":	"chi",		"ºì":	"hong",
"»Æ":	"huang",	"ÂÌ":	"lu",
"Çà":	"qing",		"À¶":	"lan",
"×Ï":	"zi",		"ÎÚ":	"wu",
"ºÚ":	"hei",		"Òø":	"yin",
"°×":	"bai",		"½ð":	"jin",
"»Ò":	"hui",		"Ä¾":	"mu",
"Ë®":	"shui",		"»ð":	"huo",
"ÍÁ":	"tu",		"Î¸":	"wei",
"¹í":	"gui",		"ÔÂ":	"yue",
"Öì":	"zhu",		"ÈÕ":	"ri",
"¶·":	"dou",		"õþ":	"zui",
"¿ü":	"kui",		"²Î":	"shen"
]);

mapping animal_list =([
"ÍÃ":	"tu",		"ºü":	"hu",
"Áú":	"long",		"òÔ":	"jiao",
"»¢":	"hu",		"±ª":	"bao",
"Âí":	"ma",		"Â¹":	"lu",
"Ñò":	"yang",		"Éß":	"she",
"â¯":	"zhang",	"¼¦":	"ji",
"¹·":	"gou",		"ÀÇ":	"lang",
"Ô³":	"yuan",		"ºï":	"hou",
"Êó":	"shu",		"Å£":	"niu",
"Öí":	"zhu",		"òð":	"fu",
"²ò":	"chai",		"Ì¡":	"lai",
"áô":	"fei",		"òþ":	"mang",
"ÐÜ":	"xiong",	"Ïó":	"xiang",
"õõ":	"diao",		"Àê":	"li",
"âµ":	"huan",		"î¼":	"pi",
"Ñà":	"yan",		"ò¾":	"yin",
"ïô":	"zhi",		"áó":	"pao",
"â¥":	"ni",		"éá":	"ao",
"Áç":	"ling",		"÷ä":	"ji",
"ÐÉ":	"xing",
]);

mapping animal_names = ([
"ºüÀê":"huli",		"ºÚÐÜ":"heixiong",
"¹·ÐÜ":"gouxiong",	"°×ÐÜ":"baixiong",
"Ð«×Ó":"xiezi",		"ó¸òÜ":"chanchu",
"òÚò¼":"wugong",	"ÍÁ±î":"tubie",
"·É»È":"feihuang",	"»È³æ":"huangchong",
"´óÇà³æ":"daqingchong",	"³ô³æ":"chouchong",
"ÌøÔé":"tiaozao",	"Ê­×Ó":"shizi",
"ÀÏ»¢":"laohu",		"Ê¨×Ó":"shizi",
"»ÆÊ¨":"huangshi",	"ºÚÊ¨":"heishi",
"°×Ê¨":"baishi",	"Ò°ÍÃ":"yetu",
"»¨±ª":"huabao",	"É½±ª":"shanbao",
"²Ý±ª":"caobao",	"É½Ñò":"shanyang",
"Âíºï":"mahou",		"â¨ºï":"mihou",
"Ô³ºï":"yuanhou",	"»ÒÀÇ":"huilang",
"Ò°Öí":"yezhu",		"Ö©Öë":"zhizhu",
"ÂíÂ¹":"malu",		"°×Â¹":"bailu",
"»ÒÂ¹":"huilu",		"ºÚÂ¹":"heilu",
"É½¼¦":"shanji",	"Ò°¼¦":"yeji",
"ïô¼¦":"zhiji",		"´Ìâ¬":"ciwei",
"»¨ºüÀê":"huahuli",	"°×ºüÀê":"baihuli",
"»ÒºüÀê":"huihuli",	"ÐÉÐÉ":"xingxing",
"áôáô":"feifei",	"°×Âí":"baima",
"ºìÂí":"hongma",	"ºÚÂí":"heima",
"°×Ã¨":"baimao",	"»¨Ã¨":"huamao",
"ºÚÃ¨":"heimao",	"Ò°Ã¨":"yemao",
"Ò°Âí":"yema",		"Ò°Â¿":"yelu",
"°×ÍÃ":"baitu",		"»ÒÍÃ":"huitu",
"Ë®Å£":"shuiniu",	"êóÅ£":"maoniu",
"Ò°Å£":"yeniu",		"°×Êó":"baishu",
"»ÒÊó":"huishu",	"ºÚÂìÒÏ":"heimayi",
"ÂìÒÏ":"mayi",		"°×ÒÏ":"baiyi",
"É½ÀÏÊó":"shanlaoshu",	"»¨Éß":"huashe",
"ÇàÉß":"qingshe",	"°×Éß":"baishe",
"»Ò°ßÉß":"huibanshe",	"¾Þòþ":"jumang",
"Ë®Éß":"shuishe",	"º£Àê":"haili",
"ºÓÀê":"heli",
]);

mapping middle_list =([
"½Å"	:	"jiao",		"Í·"	:	"tou",
"Î²"	:	"wei",		"×ì"	:	"zui",
"¶ú"	:	"er",		"ÑÛ"	:	"yan",
"±Ç"	:	"bi",		"ÑÀ"	:	"ya",
"Éà"	:	"she",		"Éí"	:	"shen",
"×¦"	:	"zhua",
]);
string *title_list = ({ 
	"ÔÂ¹¬ÆúÍ½",	"½«¾ü¸®ÅÑ½«", 
	"´óÑ©É½ÄõÑý",	"ÎÞµ×¶´ÄõÑý",
	"·½´çÉ½ÆúÍ½",	"Îå×¯¹ÛÄõÍ½", 
	"µØ¸®Ô©¹í",	"Áú¹¬ÆúÍ½",
	"Ìì¹¬ÅÑ½«",	"·½´çÑýµÀ",
	"ÎÞµ×¶´Ð¡Ñý",	"Îå×¯¹Û¶ñÍ½",
	"ÆÕÍÓ¶ñÉ®",
});	

varargs mapping random_name(string type)
{
	mapping name;
	int a,b,c;
	string *surnames, *middle_names, *last_names;
	string temp_name, *temp_id, long;
	
	name=allocate_mapping(3);
	
	switch(type)
	{
		case "male" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(male_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +male_name[last_names[c]],
				   surname[surnames[a]]});
		}
		if(random(2)==0)
			long=HIM"½­ºþÓÎÏÀ"NOR;
		if(random(2)==1)
			long=HIG"´óÃ÷¹¬½õÒÂÎÀ"NOR;
        if(random(2)==2)
			long=HIC"¿ª·â¸®²¶¿ì"NOR;
		name=([
			"name" : temp_name,
			"id"   : temp_id,
//			"title": YEL"²¶¿ì"NOR,
            "title"   : long,
		]);
		break;
		case "female" :
		surnames=keys(surname);
		middle_names=keys(middle_name);
		last_names=keys(female_name);
		a=random(sizeof(surnames));
		b=random(sizeof(middle_names));
		c=random(sizeof(last_names));
		if(random(100)>20)
		{
			temp_name=surnames[a]
				 + middle_names[b]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +middle_name[middle_names[b]]
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		else {
			temp_name=surnames[a]
				 + last_names[c];
			temp_id=({surname[surnames[a]]+" "
				   +female_name[last_names[c]],
				   surname[surnames[a]]});
		}
		if(random(2)==0)
			long=HIM"º¼ÖÝ³Ç¸è¼Ë"NOR;
		if(random(2)==1)
			long=HIG"´óÃ÷¹¬Îè¼§"NOR;
        if(random(2)==2)
			long=HIC"¿ª·â¸®¸èÅ®"NOR;
		name=([
			"name" : temp_name,
			"id"   : temp_id,
//			"title": HIM"´óÃ÷¹¬¸èÅ®"NOR,
            "title"   : long,
		]);
		break;
		case "japan" :
		surnames=keys(jp_surname);
		last_names=keys(jp_name);
		a=random(sizeof(surnames));
		b=random(sizeof(last_names));
		name=([
			"name" : surnames[a]
				 + last_names[b],
			"id"   : ({jp_surname[surnames[a]]+" "
				   +jp_name[last_names[b]],
				   jp_surname[surnames[a]]}),
			"title": WHT"ÈÕ±¾ÎäÊ¿"NOR,
		]);
		break;
                case "yaoguai":
		if(random(2))
		{
			surnames=keys(animal_list);
			middle_names=keys(middle_list);
			a=random(sizeof(surnames));
			b=random(sizeof(middle_names));
			c=random(sizeof(surnames));
			name=([
				"name" 	: surnames[a]+
					  middle_names[b]+
					  surnames[c],
				"id"	: ({animal_list[surnames[a]]+
					    middle_list[middle_names[b]]+" "+
					    animal_list[surnames[c]],
					    animal_list[surnames[c]]}),
                                "title"	:title_list[random(sizeof(title_list))],
			]);
		}
		else
		{
			if(random(2))
			{
				surnames=keys(color_list);
				middle_names=keys(animal_list);
				a=random(sizeof(surnames));
				b=random(sizeof(middle_names));
				c=random(2);
				temp_name=surnames[a]+
					  middle_names[b];
				temp_name+=c?"¾«":"¹Ö";
				if(c)
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"jing", "jing"});
				else
					temp_id=({color_list[surnames[a]]+
						  animal_list[middle_names[b]]+" "+
					  	"guai",	"guai"});
			}
			else
			{
				surnames=keys(animal_names);
				a=random(sizeof(surnames));
				b=random(2);
				temp_name=surnames[a];
				temp_name+=b?"¾«":"¹Ö";
				if(b)
					temp_id=({animal_names[surnames[a]]+" "+
						  "jing", "jing"});
				else
					temp_id=({animal_names[surnames[a]]+" "+
						  "guai", "guai"});
			}
			name=([
				"name" : temp_name,
				"id"   : temp_id,
				"title": "NONE",
			]);
		}
		break;
		default:
		name=([
			"name" : "²âÊÔ",
			"id"   : ({"test"}),
		]);
		break;
	}
	return name;
}
