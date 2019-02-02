/*
 * かなローマ字変換をするプログラム Ver.0.94
 */

#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <stdbool.h>
#include  <ctype.h>

#define isconsonant(x)  (index("kstnhmyrwzjpbcgfx",(x))!=0)

static  char  *tab[]={
        "wa" ,"わ"  ,"wi" ,"うぃ",      "we" ,"うぇ","wo" ,"を"  ,
        "wha","うぁ","whi","うぃ",      "whe","うぇ","who","うぉ",
        "a"  ,"あ"  ,"i"  ,"い"  ,"u"  ,"う"  ,"e"  ,"え"  ,"o"  ,"お"  ,
        "wu","う",
        "whu","う",
        "tha","てゃ","thi","てぃ","thu","てゅ","the","てぇ","tho","てょ",
        "va" ,"ゔぁ","vi","ゔぃ", "ve","ゔぇ","vo","ゔぉ", "vu","ゔ",
        "ja" ,"じゃ", "ju" ,"じゅ","je" ,"じぇ","jo" ,"じょ", "ji","じ",
        "dha","でゃ","dhi","でぃ","dhu","でゅ","dhe","でぇ","dho","でょ",
        "jya","じゃ","jyi","じぃ","jyu","じゅ","jye","じぇ","jyo","じょ",
        "kya","きゃ","kyi","きぃ","kyu","きゅ","kye","きぇ","kyo","きょ",
        "sha","しゃ", "shu","しゅ","she","しぇ","sho","しょ",
        "sya","しゃ","syi","しぃ","syu","しゅ","sye","しぇ","syo","しょ",
        "shi","し",
        "cha","ちゃ","chi","ち"  ,"chu","ちゅ","che","ちぇ","cho","ちょ",
        "tya","ちゃ","tyi","ちぃ","tyu","ちゅ","tye","ちぇ","tyo","ちょ",
        "cya","ちゃ","cyi","ちぃ","cyu","ちゅ","cye","ちぇ","cyo","ちょ",
        "tsu","つ"  ,
        "ta" ,"た"  ,"ti" ,"ち"  ,"tu" ,"つ"  ,"te" ,"て"  ,"to" ,"と"  ,
        "nya","にゃ","nyi","にぃ","nyu","にゅ","nye","にぇ","nyo","にょ",
        "hya","ひゃ","hyi","ひぃ","hyu","ひゅ","hye","ひぇ","hyo","ひょ",
        "fa" ,"ふぁ","fi" ,"ふぃ", "fe" ,"ふぇ","fo" ,"ふぉ", "fu" ,"ふ",
        "mya","みゃ","myi","みぃ","myu","みゅ","mye","みぇ","myo","みょ",
        "rya","りゃ","ryi","りぃ","ryu","りゅ","rye","りぇ","ryo","りょ",
        "gya","ぎゃ","gyi","ぎぃ","gyu","ぎゅ","gye","ぎぇ","gyo","ぎょ",
        "gwa","ぐぁ","gwi","ぐぃ","gwu","ぐぅ","gwe","ぐぇ","gwo","ぐぉ",
        "dya","ぢゃ","dyi","ぢぃ","dyu","ぢゅ","dye","ぢぇ","dyo","ぢょ",
        "bya","びゃ","byi","びぃ","byu","びゅ","bye","びぇ","byo","びょ",
        "pya","ぴゃ","pyi","ぴぃ","pyu","ぴゅ","pye","ぴぇ","pyo","ぴょ",
        "ka" ,"か"  ,"ki" ,"き"  ,"ku" ,"く"  ,"ke" ,"け"  ,"ko" ,"こ"  ,
        "sa" ,"さ"  ,"si" ,"し"  ,"su" ,"す"  ,"se" ,"せ"  ,"so" ,"そ"  ,
        "na" ,"な"  ,"ni" ,"に"  ,"nu" ,"ぬ"  ,"ne" ,"ね"  ,"no" ,"の"  ,
        "ha" ,"は"  ,"hi" ,"ひ"  ,"hu" ,"ふ"  ,"he" ,"へ"  ,"ho" ,"ほ"  ,
        "ma" ,"ま"  ,"mi" ,"み"  ,"mu" ,"む"  ,"me" ,"め"  ,"mo" ,"も"  ,
        "ya" ,"や"  ,"yi" ,"ゐ"  ,"yu" ,"ゆ"  ,"ye" ,"ゑ"  ,"yo" ,"よ"  ,
        "ra" ,"ら"  ,"ri" ,"り"  ,"ru" ,"る"  ,"re" ,"れ"  ,"ro" ,"ろ"  ,
        "ga" ,"が"  ,"gi" ,"ぎ"  ,"gu" ,"ぐ"  ,"ge" ,"げ"  ,"go" ,"ご"  ,
        "za" ,"ざ"  ,"zi" ,"じ"  ,"zu" ,"ず"  ,"ze" ,"ぜ"  ,"zo" ,"ぞ"  ,
        "da" ,"だ"  ,"di" ,"ぢ"  ,"du" ,"づ"  ,"de" ,"で"  ,"do" ,"ど"  ,
        "ba" ,"ば"  ,"bi" ,"び"  ,"bu" ,"ぶ"  ,"be" ,"べ"  ,"bo" ,"ぼ"  ,
        "pa" ,"ぱ"  ,"pi" ,"ぴ"  ,"pu" ,"ぷ"  ,"pe" ,"ぺ"  ,"po" ,"ぽ"  ,
        "ca" ,"か"  ,"ci" ,"し"  ,"cu" ,"く"  ,"ce" ,"せ"  ,"co" ,"こ"  ,
        "n" ,"ん"  ,"-"  ,"ー"  ,
        "ltu","っ","ltsu","っ",
        "xtu","っ"  , "xtsu","っ",
        "lya","ゃ"  ,"lyu","ゅ"  ,"lyo","ょ"  ,
        "la" ,"ぁ"  ,"li" ,"ぃ"  ,"lu" ,"ぅ"  ,"le" ,"ぇ"  ,"lo" ,"ぉ"  ,
        "xya","ゃ"  ,"xyu","ゅ"  ,"xyo","ょ"  ,
        "xa" ,"ぁ"  ,"xi" ,"ぃ"  ,"xu" ,"ぅ"  ,"xe" ,"ぇ"  ,"xo" ,"ぉ"  ,
        "lwa","ゎ"  ,"xwa","ゎ",
                NULL,NULL };

bool  isutf8v(char *s) {
static  char  *utf8v[]={"あ","い","う","え","お","や","ゆ","よ",NULL };
  for(int i=0;utf8v[i]!=NULL;i++) {
    if (strncmp(utf8v[i],s,strlen(utf8v[i]))==0)
      return true;
    }
  return false;
}

void  romaji2kana(char *s,char *o) {
    while(s[0]!='\0') {

      // 子音が続いていれば、「っ」に変換
      if (isconsonant(s[0]) && (*s==s[1])) {
        s++;
        strcpy(o,"っ");
        o+=strlen("っ");
        continue;
        }

      // 'n'の次に、行末か、長音か、アポストロフィがあれば、「ん」に変換
      if (s[0]=='n' &&
           ((s[1]=='\0')||(s[1]=='\n')||(s[1]=='-')||s[1]=='\'')) {
          strcpy(o,"ん");
          o+=strlen("ん");
          s+=s[1]=='\''?2:1;
          continue;
          }
        
      // ローマ字かなテーブルを使って変換
      bool f=false;
      for(int idx=0;tab[idx]!=NULL;idx+=2) {
        if (strncmp(tab[idx],s,strlen(tab[idx]))==0) {
          strcpy(o,tab[idx+1]);
          o+=strlen(tab[idx+1]);
          s+=strlen(tab[idx]);
          f= true;
          break;
          }
        }
      if (!f) s++;
      }
    *o='\0';
    return;
}

void  kana2romaji(char *s,char *o) {
    char  *p=o;
    int   nlen=strlen("ん");
    
    while(*s!='\0') {
    // 「ん」に母音か、「n」行が続くなら、「n'」に変換
    if ((strncmp("ん",s,nlen)==0) && isutf8v(s+nlen)) {
        strncpy(o,"n'",2);
        o+=2;
        s+=nlen;
        continue;
      }

    // ローマ字かなテーブルを使って変換
    bool f=false;
    for(int idx=0;tab[idx]!=NULL;idx+=2) {
      if (strncmp(tab[idx+1],s,strlen(tab[idx+1]))==0) {
          strcpy(o,tab[idx]);
          o+=strlen(tab[idx]);
          s+=strlen(tab[idx+1]);
          f=true;
          break;
          }
      }
    if (!f) s++;
    }

    *o='\0';

   // 変換後、「ltu」の後に子音が続いていれば、子音を重ねる。
    for(;*p;p++) {
      if (strncmp(p,"ltu",3)==0 && isconsonant(p[3])) {
          p[0]=p[3];
          strcpy(p+1,p+3);
          }
      }
    return;
}
        
int main(int argc,char *argv[]) {
  char    word[1024];

  if (argc!=2) {
    fprintf(stderr,"Usage (1): %s ことば\n",argv[0]);
    fprintf(stderr,"Usage (2): %s kotoba\n",argv[0]);
    exit(1);
    }

  if(isalpha(argv[1][0]))
    romaji2kana(argv[1],word);
  else
    kana2romaji(argv[1],word);
  
  printf("%s\n",word);
  
  exit(0);
}