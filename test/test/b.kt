    // 创建前台通知
    val channelId = "location_service"
    val channelName = "位置服务"
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
        val channel = NotificationChannel(
            channelId,
            channelName,
            NotificationManager.IMPORTANCE_LOW
        )
        val manager = getSystemService(Context.NOTIFICATION_SERVICE) as NotificationManager
        manager.createNotificationChannel(channel)
    }

    val notification: Notification = NotificationCompat.Builder(this, channelId)
        .setContentTitle("正在记录位置")
        .setContentText("旅行轨迹记录中")
        .setSmallIcon(R.mipmap.ic_launcher)
        .setOngoing(true)
        .build()

    startForeground(1, notification)    //启动