import re

# ========================================
# 一、子密钥生成
# (1) 初始置换 64->56
# 64位的种子密钥经过PC_1置换后，生成56位的密钥
# (2) 划分 56->(28,28)
# 经过初始置换后的56位密钥被均分成C0和D0两部分
# (3) 循环左移
# 第一轮，C0和D0根据移位次数表各自进行循环左移
# 得到C1和D1
# 每一轮的C和D值是由上一轮的C和D值循环左移得到的
# (4) 合并 (28,28)->56->48
# 左移后的两部分再次合并,通过一个选择压缩表(PC_2)
# 得到这一轮的子密钥
# (5)重复3、4操作,最终得到16个子密钥
# ========================================

# 置换选择表1(PC_1) 64->56
PC_1 = [57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4
        ]

# 选择压缩表2(PC_2) 56->48
PC_2 = [14, 17, 11, 24, 1, 5, 3, 28,
        15, 6, 21, 10, 23, 19, 12, 4,
        26, 8, 16, 7, 27, 20, 13, 2,
        41, 52, 31, 37, 47, 55, 30, 40,
        51, 45, 33, 48, 44, 49, 39, 56,
        34, 53, 46, 42, 50, 36, 29, 32
        ]

# 移位次数表
shift_num = [1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1]


def pc_1_change(bin_key):
    """初始置换

    64位的种子密钥经过PC_1置换后，生成56位的密钥
    """
    return [bin_key[i - 1] for i in PC_1]  # 列表形式


def shift_left(bin_key, num):
    """实现C和D的循环左移"""
    return bin_key[num:] + bin_key[:num]


def pc_2_change(bin_key):
    """选择压缩

    56位的密钥经过PC_2压缩，生成48位子密钥
    """
    return ''.join([bin_key[i - 1] for i in PC_2])  # 列表转字符串


def get_subkey_list(bin_key):
    """生成16轮的加解子密钥"""
    subkey_list = []  # 存储16轮子密钥
    # 1. 初始置换 64->58
    temp = pc_1_change(bin_key)
    # 2. 循环左移
    for i in shift_num:
        temp[:28] = shift_left(temp[:28], i)  # C部分循环左移
        temp[28:] = shift_left(temp[28:], i)  # D部分循环左移
        subkey_list.append(pc_2_change(temp))  # 生成子密钥
    # print(subkey_list[-1])
    return subkey_list


# ========================================
# 二、DES加解密实现
# ========================================

# 初始置换表IP 64->64
IP = [58, 50, 42, 34, 26, 18, 10, 2,
      60, 52, 44, 36, 28, 20, 12, 4,
      62, 54, 46, 38, 30, 22, 14, 6,
      64, 56, 48, 40, 32, 24, 16, 8,
      57, 49, 41, 33, 25, 17, 9, 1,
      59, 51, 43, 35, 27, 19, 11, 3,
      61, 53, 45, 37, 29, 21, 13, 5,
      63, 55, 47, 39, 31, 23, 15, 7
      ]

# 逆置换表_IP 64->64
_IP = [40, 8, 48, 16, 56, 24, 64, 32, 39,
       7, 47, 15, 55, 23, 63, 31, 38, 6,
       46, 14, 54, 22, 62, 30, 37, 5, 45,
       13, 53, 21, 61, 29, 36, 4, 44, 12,
       52, 20, 60, 28, 35, 3, 43, 11, 51,
       19, 59, 27, 34, 2, 42, 10, 50, 18,
       58, 26, 33, 1, 41, 9, 49, 17, 57, 25
       ]

# 扩展置换表E 32->48
E = [32, 1, 2, 3, 4, 5, 4, 5,
     6, 7, 8, 9, 8, 9, 10, 11,
     12, 13, 12, 13, 14, 15, 16, 17,
     16, 17, 18, 19, 20, 21, 20, 21,
     22, 23, 24, 25, 24, 25, 26, 27,
     28, 29, 28, 29, 30, 31, 32, 1
     ]

# S盒 48->32
S1 = [14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
      0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
      4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
      15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13
      ]
S2 = [15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
      3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
      0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
      13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9
      ]
S3 = [10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
      13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
      13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
      1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12
      ]
S4 = [7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
      13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
      10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
      3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14
      ]
S5 = [2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
      14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
      4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
      11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3
      ]
S6 = [12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
      10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
      9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
      4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13
      ]
S7 = [4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
      13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
      1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
      6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12
      ]
S8 = [13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
      1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
      7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
      2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11
      ]
S = [S1, S2, S3, S4, S5, S6, S7, S8]

# P盒
P = [16, 7, 20, 21, 29, 12, 28, 17,
     1, 15, 23, 26, 5, 18, 31, 10,
     2, 8, 24, 14, 32, 27, 3, 9,
     19, 13, 30, 6, 22, 11, 4, 25
     ]


# encrypt
def ip_change(bin_text):
    """初始置换"""
    return [bin_text[i - 1] for i in IP]


def s_box(bin_result):
    """S盒替换"""
    int_result = []
    result = ''
    for i in range(8):
        # 二进制行号
        bin_row = bin_result[i][0] + bin_result[i][5]
        # 二进制列号
        bin_col = ''.join(bin_result[i][j] for j in range(1, 5))
        # 获取对应的十进制数
        int_result.append(S[i][16 * int(bin_row, base=2) + int(bin_col, base=2)])
        # 十进制转成二进制
        result += bin(int_result[-1])[2:].zfill(4)
    return result


def p_box(result):
    """P盒置换"""
    return ''.join(result[i - 1] for i in P)


def f(R, bin_key):
    """轮函数f()"""
    # 1.将R由32位扩展成48位
    R_ext = [R[i - 1] for i in E]
    # print(R_ext)
    # 2.与子密钥进行逐位异或
    bin_temp = [str(int(r) ^ int(k)) for r, k in zip(R_ext, bin_key)]
    # 6个字符为一组，共8组
    bin_result = [''.join(bin_temp[i:i + 6]) for i in range(0, len(bin_temp), 6)]
    print(bin_result)
    # 3.S盒替换 48->32
    result = s_box(bin_result)
    # 4.P盒置换 32->32
    return p_box(result)


def _ip_change(bin_text):
    """进行IP-1逆置换"""
    return ''.join(bin_text[i - 1] for i in _IP)


def des_cipher(bin_text, bin_key, reverse_keys=False):
    """通用DES加密解密函数"""
    # 1. 初始置换IP
    bin_text = ip_change(bin_text)
    # 2. 分成左右两部分L、R
    L, R = bin_text[:32], bin_text[32:]
    # 3. 获得16轮子密钥
    subkey_list = get_subkey_list(bin_key)
    if reverse_keys:
        subkey_list = subkey_list[::-1]  # 解密时反转子密钥列表
    # 4. 进行16轮迭代
    for i in subkey_list:
        R_temp = R
        # 轮函数f()结果和L进行异或
        R = ''.join(str(int(r) ^ int(l)) for r, l in zip(f(R, i), L))
        L = R_temp
    # 5. 进行IP-1逆置换 64->64
    return _ip_change(R + L)  # 输出二进制字符串


# 使用示例
def str2bin(text):
    """字符串转二进制字符串"""
    return ''.join(bin(byte)[2:].zfill(8) for byte in text.encode())


def bin2str(bin_text):
    """二进制字符串转字符串"""
    # 1.将二进制字符串按8位分割，并转换为字节数组
    byte_array = bytearray(int(i, 2) for i in re.findall(r'.{8}', bin_text) if int(i, 2) != 0)
    # 2.将字节序列解码为字符串
    return byte_array.decode()


def is_valid_key(key):
    """检查密钥是否有效 64bit"""
    return len(key.encode()) == 8


def des_encrypt(plaintext, key):
    """DES加密"""
    # 1.明文转成二进制字符串, 0填充至64的倍数
    bin_plaintext = str2bin(plaintext)
    padding_len = (64 - (len(bin_plaintext) % 64)) % 64
    bin_padding_plaintext = bin_plaintext + '0' * padding_len
    # 2.进行64位分组加密
    bin_group_64 = re.findall(r'.{64}', bin_padding_plaintext)
    bin_ciphertext = ''
    for g in bin_group_64:
        bin_ciphertext += des_cipher(g, str2bin(key))
    # 3.密文转为16进制输出
    bin_group_4 = re.findall(r'.{4}', bin_ciphertext)
    hex_ciphertext = ''
    for g in bin_group_4:
        hex_ciphertext += format(int(g, 2), 'x')
    return hex_ciphertext


def des_decrypt(hex_ciphertext, key):
    """DES解密"""
    # 1.16进制密文转为2进制字符串
    bin_ciphertext = ''.join(bin(int(h, 16))[2:].zfill(4) for h in hex_ciphertext)
    # 2.进行64位分组解密
    bin_group_64 = re.findall(r'.{64}', bin_ciphertext)
    bin_deciphertext = ''
    for g in bin_group_64:
        bin_deciphertext += des_cipher(g, str2bin(key), reverse_keys=True)
    # 3.将解密密文转为字符串输出
    return bin2str(bin_deciphertext)


def des_run():
    """DES启动界面"""
    flag = True
    while flag:
        print('=' * 3, "DES加密解密", '=' * 3)
        print('[1]加密')
        print('[2]解密')
        print('[0]退出')
        choice = input('请输入你的选择：')
        match choice:
            case '0':
                flag = False
            case '1':
                plaintext = input('请输入明文:')
                key = input('请输入密钥(64bit):')
                if not is_valid_key(key):
                    print('密钥长度错误')
                    continue
                ciphertext = des_encrypt(plaintext, key)
                print(f'密文:{ciphertext}')
            case '2':
                ciphertext = input('请输入密文:')
                key = input('请输入密钥(64bit):')
                if not is_valid_key(key):
                    print('密钥长度错误')
                    continue
                print(f'解密:{des_decrypt(ciphertext, key)}')
            case _:
                print('输入错误')
    print('=' * 15)


if __name__ == '__main__':
    des_run()
