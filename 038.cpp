// Count and Say
// 如果当前个数是0，那么个数=1，char为当前位置的字符
// 如果当前位置字符=char，个数+1
// 如果！=，加到结果里
// 记得最后一步的char不要忘加（循环结束后）
// string += int + '0': 表示加一位数字字符

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i = 1; i < n; i++) {
            int cnt = 0;
            string tmp; // store current string
            char cur; // current char for counting
            int len = res.length();
            for(int j = 0; j < len; j++) {
                if(cnt == 0) {
                    cur = res[j];
                    cnt++;
                }
                else if(res[j] == cur) {
                    cnt++;
                }
                else {
                    tmp += '0'+cnt;
                    tmp += cur;
                    cnt = 1;
                    cur = res[j];
                }
            }
            tmp += '0'+cnt;
            tmp += cur;
            res = tmp;
        }
        return res;
    }
};

// class Solution {
// public:
//     string countAndSay(int n) {
//         string res = "1";
//         for(int i = 1; i < n; i++)
//         {
//             int cnt = 0;
//             string tmp = "";
//             char prev;
//             int len = res.length();
//             cout << len << endl;
//             cout << res[0] << endl;
//             for(int j = 0; j < len; j++)
//             {
//                 if(cnt == 0)
//                 {
//                     prev = res[j];
//                     cnt = 1;
//                 }
//                 else if(prev == res[j])
//                 {
//                     cnt++;
//                 }
//                 else
//                 {
//                     tmp += cnt + '0';
//                     tmp += prev;
//                     prev = res[j];
//                     cnt = 1;
//                 }
//             }
//             tmp += cnt + '0';
//             cout << tmp;
//             tmp += prev;
//             cout << " " << tmp << endl;
//             res = tmp;
//             cout << res << endl;
//         }
//         return res;
//     }
// };

// // string res = "1";
        
// //         for(int i = 1; i < n; i++ ){
            
// //             int count = 0;
// //             string tmpres = "";
// //             char pre;
            
// //             for (auto c : res){
// //                 if (count == 0){
// //                     pre = c;
// //                     count += 1;
// //                 }
// //                 else{
// //                     if (pre == c){
// //                         count += 1;
// //                     }
// //                     else{
// //                         tmpres +=  count + '0';
// //                         tmpres += pre;
// //                         pre = c;
// //                         count = 1;
// //                     }
// //                 }
// //             }
            
// //             tmpres += count + '0';
// //             tmpres += pre;
// //             res = tmpres;
// //         }
        
// //         return res;