package com.example.chapter14.config;

import lombok.Data;
import org.springframework.boot.context.properties.ConfigurationProperties;
import org.springframework.context.annotation.Configuration;

@Data
@Configuration
@ConfigurationProperties(prefix = "com.ryj")
public class RyjProperties {
    /**
     * 这是一个测试用例
     */
    private String from;
}
