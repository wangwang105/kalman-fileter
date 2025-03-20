#include <stdio.h>
#include "kalman_filter.h"


// init_value 设为 25.0，表示初始温度估计为 25℃。
// init_covariance 设为 1.0，表示对初始估计有一定的不确定性。
// process_noise 设为 0.0001，假设温度变化较为平稳。
// measurement_noise 设为 0.01，基于对测量噪声的估计。

// 初始化卡尔曼滤波器
void kalmanInit(KalmanFilter *kf, float init_value, float init_covariance,
                float process_noise, float measurement_noise) {
    kf->x = init_value;
    kf->p = init_covariance;
    kf->q = process_noise;
    kf->r = measurement_noise;
    kf->k = 0;
}

// 卡尔曼滤波更新函数：输入新的测量值，返回滤波后的状态估计
float kalmanUpdate(KalmanFilter *kf, float measurement) {
    // 预测阶段：更新误差协方差
    kf->p = kf->p + kf->q;
    
    // 计算卡尔曼增益
    kf->k = kf->p / (kf->p + kf->r);
    
    // 更新阶段：修正状态估计
    kf->x = kf->x + kf->k * (measurement - kf->x);
    
    // 更新误差协方差
    kf->p = (1 - kf->k) * kf->p;
    
    return kf->x;
}

// int main(void) {
//     // 假设初始温度估计为25.0，初始协方差为1.0，
//     // 过程噪声q设为0.001（温度变化平缓），测量噪声r设为0.01（基于实际传感器方差估计）
//     KalmanFilter kf;
//     kalmanInit(&kf, 25.0, 1.0, 0.001, 0.01);
    
//     // 模拟一系列温度测量数据（可以替换为实际传感器数据）
//     float measurements[10] = {25.1, 24.9, 25.0, 25.2, 24.8, 25.1, 25.0, 25.3, 24.7, 25.0};
    
//     printf("滤波前\t滤波后\n");
//     for (int i = 0; i < 10; i++) {
//         float filtered = kalmanUpdate(&kf, measurements[i]);
//         printf("%f -> %f\n", measurements[i], filtered);
//     }
    
//     return 0;
// }
