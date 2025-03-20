# kalman filter 的简单实现

## 简介

Kalman filter 是一种用于估计动态系统状态的递归算法。它通过结合系统的模型和测量数据来提供对状态的估计，同时考虑噪声和不确定性。

## 使用方法

```C

// init_value 设为 25.0，表示初始温度估计为 25℃。
// init_covariance 设为 1.0，表示对初始估计有一定的不确定性。
// process_noise 设为 0.0001，假设温度变化较为平稳。
// measurement_noise 设为 0.01，基于对测量噪声的估计。

int main()
{
    KalmanFilter kf;
    kalmanInit(&kf,25,1,0.0001,0.01);

    while (1)
    {
        // 读取温度传感器数据
        float measurement = readTemperatureSensor();

        // 更新卡尔曼滤波器
        float estimatedTemperature = kalmanUpdate(&kf, measurement);

        // 输出估计的温度
        printf("Estimated temperature: %f\n", estimatedTemperature);
    }

}

```

