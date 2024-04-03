package main

import (
	"fmt"
	"strconv"
	"strings"
	"unicode"
)


type IPType uint8

const (
    IPInvalid IPType = 0
    IPv4 = 1
    IPv6 = 2
)

func getIPType(queryIP string) IPType {
    var ip_type IPType = IPInvalid
    for _, c := range queryIP {
        if c == '.' {
            ip_type = IPv4
        } else if c == ':' {
            ip_type = IPv6
        }
    }
    return ip_type
}

func isValidIPv4(queryIP string) bool {
    parts := strings.Split(queryIP, ".")

    if len(parts) != 4 {
        return false
    }

    for _, p := range parts {
        if len(p) > 1 && p[0] == '0' {
            return false
        }

        n, err := strconv.ParseInt(p, 10, 16)
        if err != nil || n > 255 {
            return false
        }
    }

    return true
}

func isValidIPv6(queryIP string) bool {
    parts := strings.Split(queryIP, ":")

    if len(parts) != 8 {
        return false
    }

    for _, p := range parts {
        part_length := len(p)
        if part_length < 1 || part_length > 4 {
            return false
        }

        for _, c := range p {
            if unicode.IsLetter(c) && 
            !((c <= 'f' && c >= 'a') || (c <= 'F' && c >= 'A')) {
                return false
            }
        }
    } 

    return true
}

func validIPAddress(queryIP string) string {
    var ip_type IPType = getIPType(queryIP)

    if ip_type == IPv4 && isValidIPv4(queryIP) {
        return "IPv4"
    } else if ip_type == IPv6 && isValidIPv6(queryIP) {
        return "IPv6"
    }

    return "Neither"
}

func main() {
	fmt.Println(
		validIPAddress("2001:0db8:85a3:0:0:8A2E:0370:7334"),
	)
}
