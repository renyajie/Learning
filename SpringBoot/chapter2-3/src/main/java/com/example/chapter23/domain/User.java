package com.example.chapter23.domain;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotNull;

@Data
@ApiModel
public class User {
    @ApiModelProperty
    private Long id;

    @NotNull
    @ApiModelProperty
    private String name;

    @NotNull
    @ApiModelProperty
    private Integer age;

    @NotNull
    @Email
    @ApiModelProperty
    private String email;
}
