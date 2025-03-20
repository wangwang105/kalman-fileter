#ifndef __KALMAN_FILTER_H__
#define __KALMAN_FILTER_H__


// 定义一维卡尔曼滤波器结构体
typedef struct
{
    float x; // 当前状态估计（温度）
    float p; // 估计误差协方差
    float q; // 过程噪声协方差
    float r; // 测量噪声协方差
    float k; // 卡尔曼增益
} KalmanFilter;

void kalmanInit(KalmanFilter *kf, float init_value, float init_covariance,
                float process_noise, float measurement_noise);

float kalmanUpdate(KalmanFilter *kf, float measurement);

#endif /* __KALMAN_FILTER_H__ */
