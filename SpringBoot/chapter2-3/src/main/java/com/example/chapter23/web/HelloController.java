package com.example.chapter23.web;

import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {

    @GetMapping("/")
    @ApiOperation(value = "基本跳转")
    public String index() {
        return "Hello World";
    }
}
